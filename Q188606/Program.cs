using System;
using System.Data;

namespace ConsoleApplication1
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			DataSet s = new DataSet();
			DataTable t1 = new DataTable("Table1");
			t1.Columns.Add();
			t1.Columns.Add();
			t1.Rows.Add("a", "b");
			t1.Rows.Add("c", "d");
			t1.Rows.Add("e", "f");
			t1.Rows.Add("g", "h");
			t1.Rows.Add("i", "j");
			s.Tables.Add(t1);

			t1 = new DataTable("Table2");
			t1.Columns.Add();
			t1.Columns.Add();
			t1.Columns.Add();
			t1.Columns.Add();
			t1.Rows.Add("a", "b", "c", "d");
			t1.Rows.Add("c", "d", "e", "f");
			t1.Rows.Add("e", "f", "g", "h");
			s.Tables.Add(t1);

			var t2 = s.Tables["Table1"];
			Console.WriteLine("Table1:Columns={0}.Rows={1}", t2.Columns.Count, t2.Rows.Count);
			t2 = s.Tables["Table2"];
			Console.WriteLine("Table2:Columns={0}.Rows={1}", t2.Columns.Count, t2.Rows.Count);
			Console.ReadLine();
		}
	}
}