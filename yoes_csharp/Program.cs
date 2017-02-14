using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using XMindAPI.LIB;

namespace yoes_csharp
{
  class Program
  {
    static void Main(string[] args)
    {
      // Create a new, empty workbook. If the workbook exists it will be overwritten:
      XMindWorkBook xwb = new XMindWorkBook("test.xmind");
      // Create a new sheet (at least one per workbook required):
      string sheetId = xwb.AddSheet("Vehicles");
      string centralTopicId = xwb.AddCentralTopic(sheetId, "YOES",
          XMindStructure.TreeRight);

      var reader = new StreamReader(new FileStream("headwords.txt", FileMode.Open));
      while (!reader.EndOfStream)
      {
        string headword = reader.ReadLine().Trim();
        if (headword.Length > 0)
          xwb.AddTopic(centralTopicId, headword);
      }

      xwb.Save();
    }
  }
}
