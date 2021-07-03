#include "Camera.h"

glm::mat4 Camera::calcViewMatrix() const {
	return glm::lookAt(getEye(), getTarget(), getUp());
};

glm::vec3 calcForward();
glm::vec3 calcRight();

float Camera::distanceFromEyeToTarget() const {
	return this->D;
};

const glm::vec3& Camera::getEye() const {
	return this->eye;
};
const glm::vec3& Camera::getTarget() const {
	return this->target;
};
const glm::vec3& Camera::getUp() const {
	return this->up;
};

void Camera::setFrontView(glm::vec3 eye) {
	this->eye = this->target + eye;
	this->up = { 0, 1, 0 };
};
void Camera::setTopView(glm::vec3 eye) {
	this->eye = this->target + eye;
	this->up = { -1.0, 0.0, 0.0 };
};
void Camera::setRearView(glm::vec3 eye) {
	this->eye = this->target + eye;
	this->up = { 0.0, 1.0, 0.0 };
};
void Camera::setRightView(glm::vec3 eye) {
	this->eye = this->target + eye;
	this->up = { 0.0, 1.0, 0.0 };
};
void Camera::setLeftView(glm::vec3 eye) {
	this->eye = this->target + eye;
	this->up = { 0.0, 1.0, 0.0 };
};
void Camera::setBottomView(glm::vec3 eye) {
	this->eye = this->target + eye;
	this->up = { 1.0, 0.0, 0.0 };
};
void Camera::setIsoView(glm::vec3 eye) {
	this->eye = this->target + eye;
	this->up = { 0.0, 1.0, 0.0 };
};

void orbit(glm::vec3 a, glm::vec3 b);
void pan(double u, double v);
void zoom(double factor);

void Camera::translate(glm::vec3 delta) {
	this->eye += delta;
};
void Camera::setDistanceToTarget(double D) {
	this->D = D;
};
void transform(const glm::mat4& trf);
void rotate(glm::vec3 point, glm::vec3 axis, double angle);

void Camera::setEyeTargetUp(glm::vec3 newEye, glm::vec3 newTarget, glm::vec3 newUp) {
	this->eye = newEye;
	this->target = newTarget;
	this->up = newUp;
	this->D = sqrt(pow(this->target.x - this->eye.x, 2) + pow(this->target.y - this->eye.y, 2) + pow(this->target.z - this->eye.z, 2));
};