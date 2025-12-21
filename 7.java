/*
7. our college wants to display results in a browser using an applet. Create an applet that:
- Reads two marks from <PARAM> tags using getParameter()
- Calculates total and displays pass/fail using paint()
- Write the corresponding HTML APPLET tag.
-Explain how the applet lifecycle (init(), start(), paint(), stop(), destroy()) works in this
example. */

import java.applet.Applet;
import java.awt.Graphics;

/*
<applet code="ResultApplet.class" width="300" height="200">
    <param name="mark1" value="45">
    <param name="mark2" value="40">
</applet>
*/

public class ResultApplet extends Applet {

    int m1, m2, total;

    public void init() {
        m1 = Integer.parseInt(getParameter("mark1"));
        m2 = Integer.parseInt(getParameter("mark2"));
        total = m1 + m2;
    }

    public void paint(Graphics g) {
        g.drawString("Mark 1 : " + m1, 20, 40);
        g.drawString("Mark 2 : " + m2, 20, 60);
        g.drawString("Total  : " + total, 20, 80);

        if (total >= 80)
            g.drawString("Result : PASS", 20, 100);
        else
            g.drawString("Result : FAIL", 20, 100);
    }
}
// save this in html file
<html>
<body>
    <applet code="ResultApplet.class" width="300" height="200">
        <param name="mark1" value="45">
        <param name="mark2" value="40">
    </applet>
</body>
</html>
