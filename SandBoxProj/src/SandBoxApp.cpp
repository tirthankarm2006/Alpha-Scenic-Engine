#include "AlphaScenic.h"

class SandBox : public AS::Application {
public:
	SandBox() {

	}

	~SandBox() {

	}
};

AS::Application* AS::CreateApplication() {
	return new SandBox();
}