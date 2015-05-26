using System;
using System.Data;
using System.Data.SqlClient;

namespace Q183988
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			var sConnect = @"Data Source=LOCALHOST\SQLSERVER;Initial Catalog=test;Integrated Security=True";
			var conn = new SqlConnection(sConnect);
			var sCommand = "SELECT [NAME] FROM [T1] WHERE [NAME] = @Name";
			var cmd = new SqlCommand(sCommand, conn);
			cmd.Parameters.Add("@Name", SqlDbType.NVarChar).Value = "北京";

			conn.Open();
			var o = cmd.ExecuteScalar();
			Console.WriteLine("Result is :{0}\n", o.ToString());
			conn.Close();

			Console.ReadLine();
		}
	}
}