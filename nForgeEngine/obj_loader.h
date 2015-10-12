#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <glm\glm.hpp>
#include <vector>
#include <string>

struct OBJIndex {
	unsigned int vertexIndex;
	unsigned int uvIndex;
	unsigned int normalIndex;

	bool operator<(const OBJIndex& r) const { return vertexIndex < r.vertexIndex; }
};

class IndexedModel {

public:
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;
	std::vector<unsigned int> indices;

	void CalcNormals();
protected:
private:

};

class OBJModel {

public:
	std::vector<OBJIndex> OBJIndices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	bool hasUVs;
	bool hasNormals;

	OBJModel(const std::string&);

	IndexedModel ToIndexedModel();
protected:
private:
	unsigned int FindLastVertexIndex(const std::vector<OBJIndex*>&, const OBJIndex*, const IndexedModel&);
	void CreateOBJFace(const std::string&);

	glm::vec2 ParseOBJVec2(const std::string&);
	glm::vec3 ParseOBJVec3(const std::string&);
	OBJIndex ParseOBJIndex(const std::string&, bool*, bool*);

};

#endif