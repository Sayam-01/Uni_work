<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<head><title>Lab 13 - Simple and Complex Elements</title></head>
<body>
  <h2><xsl:value-of select="Library/LibraryName"/></h2>
  <table border="1" cellpadding="5">
    <tr><th>Title</th><th>Author</th><th>Price</th></tr>
    <xsl:for-each select="Library/Book">
    <tr>
      <td><xsl:value-of select="Title"/></td>
      <td><xsl:value-of select="Author"/></td>
      <td><xsl:value-of select="Price"/> <xsl:value-of select="Price/@currency"/></td>
    </tr>
    </xsl:for-each>
  </table>
  <hr/>
  <footer style="text-align:left;font-weight:bold;">By Sayam Shrestha</footer>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
