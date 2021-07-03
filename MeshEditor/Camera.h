#include <glm/glm.hpp>
#include <iostream>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define pi 3.1415926535

class Camera {
public:
	glm::mat4 calcViewMatrix() const;

	glm::vec3 calcForward();
	glm::vec3 calcRight();

	float distanceFromEyeToTarget() const;

	const glm::vec3& getEye() const;
	const glm::vec3& getTarget() const;
	const glm::vec3& getUp() const;

	void setFrontView(glm::vec3 eye);
	void setTopView(glm::vec3 eye);
	void setRearView(glm::vec3 eye);
	void setRightView(glm::vec3 eye);
	void setLeftView(glm::vec3 eye);
	void setBottomView(glm::vec3 eye);
	void setIsoView(glm::vec3 eye);

	void orbit(glm::vec3 a, glm::vec3 b);
	void pan(double u, double v);
	void zoom(double factor);

	void translate(glm::vec3 delta);
	void setDistanceToTarget(double D);
	void transform(const glm::mat4& trf);
	void rotate(glm::vec3 point, glm::vec3 axis, double angle);

	void setEyeTargetUp(glm::vec3 newEye, glm::vec3 newTarget, glm::vec3 newUp);

private:
	glm::vec3 eye;
	glm::vec3 target;
	glm::vec3 up;
	float D;
};
