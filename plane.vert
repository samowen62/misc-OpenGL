attribute vec4 v_coord;
attribute vec3 v_normal;
uniform mat4 MV;
uniform mat4 P;
varying vec3 normal;
varying vec3 eye;

void main()
{
	// inline comments should work
	gl_Position = P*MV*v_coord;	// like this one
	
	vec3 vertpos = MV * v_coord;
	eye = -vertpos;
	v_normal = gl_Normal;
	normal = v_normal;
}
