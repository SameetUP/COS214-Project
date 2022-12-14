#include "UnstableState.h"

UnstableState::UnstableState() {
	context = nullptr;
}

void UnstableState::decreaseCurrency() {
	context->removeCurrency(10);
	if (context->getCurrency()<15)
	{
		context->SetState();
	}
}

State* UnstableState::getDemotionState(){
	State* h = new FailedState();
	h->setContext(context);
	return h;
}

string UnstableState::getState(){
	return "is unstable";
}
