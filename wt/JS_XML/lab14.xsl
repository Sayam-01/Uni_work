<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<!-- This XSLT transforms the Students XML into an HTML table -->
<xsl:template match="/">
<html>
<head><title>Lab 14 - XSLT Transformation</title></head>
<body>
  <h2>Student Marks (Transformed via XSLT)</h2>
  <table border="1" cellpadding="5">
    <tr><th>Roll</th><th>Name</th><th>Marks</th></tr>
    <xsl:for-each select="Students/Student">
    <tr>
      <td><xsl:value-of select="Roll"/></td>
      <td><xsl:value-of select="Name"/></td>
      <td><xsl:value-of select="Marks"/></td>
    </tr>
    </xsl:for-each>
  </table>
  <hr/>
  <footer style="text-align:left;font-weight:bold;">By Sayam Shrestha</footer>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
