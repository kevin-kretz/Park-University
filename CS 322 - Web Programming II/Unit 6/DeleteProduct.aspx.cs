DeleteProducts.aspx.cs

using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace JW.Database
{
    public partial class DeleteProducts : System.Web.UI.Page
    {
        private void ShowProductsTable()
        {
            //Insert your connection string
            string CS = WebConfigurationManager.ConnectionStrings["KretzConnection"].ConnectionString;
            //Create the connection objects.
            SqlConnection con = new SqlConnection(CS);
            //Change the string sql to the name of your stored procedure.
            string sql = "allProductsByID";
            SqlCommand cmd = new SqlCommand(sql, con);
            cmd.CommandType = CommandType.StoredProcedure;
            SqlDataReader reader;
            //You need one tempCell variable for each column in your table. 
            //Categories table has 11 columns. 
            TableCell tempCell1, tempCell2, tempCell3, tempCell4, tempCell5, tempCell6, tempCell7, tempCell8, tempCell9, tempCell10, tempCell11;
            //Your image path might be different depending on your project!
            string ImagePath = "../Images/";
            //Use Exception handling and make sure to indent your code!
            try
            {
                con.Open();                             // Open the connection 
                reader = cmd.ExecuteReader();           // Execute the command
                while (reader.Read())
                {
                    TableRow tempRow = new TableRow();    //Create the table row
                    //Create the table cell and then, assign the values to the cell
                    tempCell1 = new TableCell();
                    tempCell1.Text = reader["productID"].ToString();
                    tempCell2 = new TableCell();
                    tempCell2.Text = reader["productName"].ToString();
                    tempCell3 = new TableCell();
                    tempCell3.Text = reader["categoryID"].ToString();
                    tempCell4 = new TableCell();
                    tempCell4.Text = reader["categoryName"].ToString();
                    tempCell5 = new TableCell();
                    tempCell5.Text = reader["description"].ToString();
                    tempCell6 = new TableCell();
                    tempCell6.Text = reader["numberInStock"].ToString();
                    tempCell7 = new TableCell();
                    tempCell7.Text = reader["cost"].ToString();
                    tempCell8 = new TableCell();
                    tempCell8.Text = reader["price"].ToString();
                    tempCell9 = new TableCell();
                    tempCell9.Text = reader["weight"].ToString();
                    tempCell10 = new TableCell();
                    System.Web.UI.WebControls.Image ProdPicture = new System.Web.UI.WebControls.Image();
                    ProdPicture.Width = 100;
                    ProdPicture.Height = 100;
                    ProdPicture.ImageUrl = String.Format(ImagePath + "{0}", reader["productImage"].ToString().Trim());
                    tempCell10.Controls.Add(ProdPicture);
                    tempCell11 = new TableCell();
                    System.Web.UI.WebControls.Image ProdThumb = new System.Web.UI.WebControls.Image();
                    ProdThumb.Width = 50;
                    ProdThumb.Height = 50;
                    ProdThumb.ImageUrl = String.Format(ImagePath + "{0}", reader["productThumbnail"].ToString().Trim());
                    tempCell11.Controls.Add(ProdThumb);
                    //These lines add the table cells to the table row. 
                    tempRow.Cells.Add(tempCell1);
                    tempRow.Cells.Add(tempCell2);
                    tempRow.Cells.Add(tempCell3);
                    tempRow.Cells.Add(tempCell4);
                    tempRow.Cells.Add(tempCell5);
                    tempRow.Cells.Add(tempCell6);
                    tempRow.Cells.Add(tempCell7);
                    tempRow.Cells.Add(tempCell8);
                    tempRow.Cells.Add(tempCell9);
                    tempRow.Cells.Add(tempCell10);
                    tempRow.Cells.Add(tempCell11);
                    //The table row must be added to the table object. 
                    ProductsTable.Rows.Add(tempRow);
                }
                reader.Close();
            }
            catch (Exception err)
            {
                //In the catch section, display any error messages or 
                //variables that you want to use to help you debug your program. 
                Message.Text = "Error reading list of categories.\n";
                Message.Text += err.Message;
                Message.Text += ImagePath + "\n";
            }
            finally
            {
                con.Close();
            }

        }
        private void ShowProductsList()
        {
            ddlProductList.Items.Clear();
            ListItem firstItem = new ListItem();
            firstItem.Text = "Select a product to delete";
            firstItem.Value = "0";
            ddlProductList.Items.Add(firstItem);
            ddlProductList.SelectedIndex = 0;
            //Insert your connection string
            string CS = WebConfigurationManager.ConnectionStrings["JWCameraShop"].ConnectionString;
            //Create the connection objects.
            SqlConnection con = new SqlConnection(CS);
            string sql = "allProductsByID";
            SqlCommand cmd = new SqlCommand(sql, con);
            cmd.CommandType = CommandType.StoredProcedure;
            SqlDataReader readerSelect;
            try
            {
                con.Open();
                readerSelect = cmd.ExecuteReader();
                while (readerSelect.Read())
                {
                    ListItem newItem = new ListItem();
                    newItem.Text = readerSelect["productName"].ToString();
                    newItem.Value = readerSelect["productID"].ToString();
                    ddlProductList.Items.Add(newItem);
                }
                readerSelect.Close();
                con.Close();
            }
            catch (Exception err)
            {
                Message.Text = "Error reading list of products.\n";
                Message.Text += err.Message + "\n";
                if (con.State.ToString() == "Open")
                {
                    con.Close();
                    Message.Text += "The Connection is now" + con.State.ToString();
                }
            }
        }

        private void DeleteProduct()
        {
            string CS = WebConfigurationManager.ConnectionStrings["JWCameraShop"].ConnectionString;
            SqlConnection con = new SqlConnection(CS);
            string sql = "deleteProduct";
            SqlCommand cmd = new SqlCommand(sql, con);
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.Parameters.AddWithValue("@deleteID", ddlProductList.SelectedValue);
            int valueReturned = 0;

            try
            {
                con.Open();
                valueReturned = cmd.ExecuteNonQuery();
                AsideMessage.Text = valueReturned.ToString() + " record successfully deleted!";
            }
            catch (Exception err)
            {
                AsideMessage.Text = "Error deleting record " + ddlProductList.SelectedValue + "\n";
                AsideMessage.Text += err.Message + "\n";
                if (con.State.ToString() == "Open")
                {
                    con.Close();
                    Message.Text += "The Connection is now: " + con.State.ToString();
                }
            }
        }

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                ShowProductsList();
                ShowProductsTable();
            }
            //page contents (table and products list need to be cleared on postback.  All
            //clearing and reloading moved to SelectedIndexChanged method due to postback causing items to be refreshed before 
            //delete could be processed.

        }
            protected void ddlProductList_SelectedIndexChanged(object sender, EventArgs e)
            {
                if (ddlProductList.SelectedValue != "0")
                {
                    DeleteProduct();
                }

                ddlProductList.Items.Clear();
                ShowProductsList();
                ShowProductsTable();
        }
        }
    }
