# misc-OpenGL
Edit worldObj.c and type 
<p>make kaeru &amp;&amp; ./kaeru</p> 
to open the modeling window to simply view your model.

WASD keys rotate object around
ZXCV zoom object and translate it up and down

This is a very rough first crack at openGL, so it's not exactly super extensive and robust

You can also run 
<p>python genMesh.py inmesh</p>
To generate a nice smooth mesh from the control points in the inmesh file.
This creates the file mesh that gives the new coordinates in nice C++ array format.
This file too is also very rough only to use for simple purposes
