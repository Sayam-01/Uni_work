<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:output method="html" encoding="UTF-8"/>

    <xsl:template match="/">

        <html>
            <head>
                <title>Student Report</title>
            </head>

            <body>

                <h1>Student Report</h1>

                <h2>Students</h2>

                <table border="1">
                    <tr>
                        <th>Student ID</th>
                        <th>First Name</th>
                        <th>Last Name</th>
                        <th>Status</th>
                    </tr>

                    <xsl:for-each select="Report/Students/Student">
                        <tr>
                            <td><xsl:value-of select="@StudId"/></td>
                            <td><xsl:value-of select="Name/First"/></td>
                            <td><xsl:value-of select="Name/Last"/></td>
                            <td><xsl:value-of select="Status"/></td>
                        </tr>
                    </xsl:for-each>
                </table>

                <h2>Courses</h2>

                <table border="1">
                    <tr>
                        <th>Course Code</th>
                        <th>Course Name</th>
                    </tr>

                    <xsl:for-each select="Report/Courses/Course">
                        <tr>
                            <td><xsl:value-of select="@CrsCode"/></td>
                            <td><xsl:value-of select="."/></td>
                        </tr>
                    </xsl:for-each>
                </table>

                <h2>Classes</h2>

                <table border="1">
                    <tr>
                        <th>Semester</th>
                        <th>Members</th>
                    </tr>

                    <xsl:for-each select="Report/Classes/Class">
                        <tr>
                            <td><xsl:value-of select="Semester"/></td>
                            <td><xsl:value-of select="ClassRoster/@Members"/></td>
                        </tr>
                    </xsl:for-each>
                </table>

                <p>By Sayam Shrestha</p>

            </body>
        </html>

    </xsl:template>

</xsl:stylesheet>