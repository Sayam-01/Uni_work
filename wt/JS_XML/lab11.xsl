<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<head><title>Lab 11 - Simple XML Element</title></head>
<body>
  <h2>Simple XML Element</h2>
  <p>Message: <xsl:value-of select="greeting/message"/></p>
  <hr/>
  <footer style="text-align:left;font-weight:bold;">By Sayam Shrestha</footer>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
