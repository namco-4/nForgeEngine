#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

using namespace glm;

class Transform {

public:
	Transform(const vec3& pos = vec3(), const vec3& rot = vec3(), const vec3& scale = vec3(1,1,1)) :
		m_pos(pos),
		m_rot(rot),
		m_scale(scale) {}

	inline mat4 getModel() const {
		mat4 posMatrix = translate(m_pos);
		mat4 rotXMatrix = rotate(m_rot.x, vec3(1, 0, 0));
		mat4 rotYMatrix = rotate(m_rot.y, vec3(0, 1, 0));
		mat4 rotZMatrix = rotate(m_rot.z, vec3(0, 0, 1));
		mat4 scaleMatrix = scale(m_scale);

		mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return posMatrix * rotMatrix * scaleMatrix;
	}

	inline vec3& GetPos() { return m_pos; }
	inline vec3& GetRot() { return m_rot; }
	inline vec3& GetScale() { return m_scale; }

	inline void SetPos(const vec3& pos) { m_pos = pos; }
	inline void SetRot(const vec3& rot) { m_rot = rot; }
	inline void SetScale(const vec3& scale) { m_scale = scale; }

protected:
private:
	vec3 m_pos;
	vec3 m_rot;
	vec3 m_scale;

};

#endif