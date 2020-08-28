#include "Camera.h"

Camera::Camera(int hsize, int vsize, float field_of_view) {
	this->hsize = hsize;
	this->vsize = vsize;
	this->field_of_view = field_of_view;
	transform = Matrix::GetIdentity();

	float half_view = tan(field_of_view / 2);

	float aspect = float(hsize) / float(vsize);

	if(aspect >= 1 ) {
		half_width = half_view;
		half_height = half_view / aspect;
	}else {
		half_width = half_view * aspect;
		half_height = half_view;
	}

	pixel_size = (half_width * 2) / float(hsize);
}

Ray Camera::RayForPixel(int px, int py) const{
	float x_offset = (float(px) + 0.5f) * pixel_size;
	float y_offset = (float(py) + 0.5f) * pixel_size;

	float world_x = half_width - x_offset;
	float world_y = half_height - y_offset;

	Vec4 pixel = transform.Inverse() * Vec4::MakePoint(world_x, world_y, -1);
	Vec4 origin = transform.Inverse() * Vec4::MakePoint(0, 0, 0);

	Vec4 direction = (pixel - origin).Normalize();

	return { origin, direction };
}

void Camera::SetTransformMat(Matrix transform) {
	this->transform = transform;
}
