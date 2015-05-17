precision highp float;
uniform mat4 MV;
uniform mat4 P;
uniform float day;
uniform float tod;
varying vec3 normal;
varying vec3 eye;

void main()
{
	vec4 diff;
	
float PI = 3.14159265358;	vec4 spec;
	vec4 amb = vec4(vec3(.4),1.0);//make .3 depend on day 0-.5
	vec3 light = vec3(cos(PI*tod/12.0 + (3.0*PI/2.0)),sin(PI*tod/12.0 + (3.0*PI/2.0)),0.0);
	light = normalize(light);
	diff = vec4(day*2.0*vec3(max(0.0,dot(normal,light))), 1.0);
	
	vec3 E = normalize(eye);
	vec3 R = reflect(-light,normal);
	spec = vec4(0.0);
	if(dot(normal, light) >= 0.0)
		spec = vec4(day*2.0)*pow(max(0.0,dot(reflect(-light, normal), E)),5.0);
	
	gl_FragColor = amb + diff + spec;
}
