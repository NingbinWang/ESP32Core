#include "Cortana.h"
#include "Configs/Version.h"
#include "Framework/Utils/lv_ext/lv_obj_ext_func.h"

using namespace Page;

Cortana::Cortana()
{
}

Cortana::~Cortana()
{

}

void Cortana::onCustomAttrConfig()
{

}

void Cortana::onViewLoad()
{
	Model.Init();
	View.Create(root);
	AttachEvent(root);
	AttachEvent(View.ui.system.icon);
}

void Cortana::onViewDidLoad()
{

}

void Cortana::onViewWillAppear()
{
//	lv_indev_set_group(lv_get_indev(LV_INDEV_TYPE_ENCODER), View.ui.group);
//	StatusBar::SetStyle(StatusBar::STYLE_BLACK);
}

void Cortana::onViewDidAppear()
{
	
}

void Cortana::onViewWillDisappear()
{
	lv_obj_fade_out(root, 300, 0);
}

void Cortana::onViewDidDisappear()
{
	lv_timer_del(timer);
}

void Cortana::onViewDidUnload()
{
	View.Delete();
	Model.Deinit();
}

void Cortana::AttachEvent(lv_obj_t* obj)
{
	lv_obj_set_user_data(obj, this);
	lv_obj_add_event_cb(obj, onEvent, LV_EVENT_PRESSED, this);
}

void Cortana::Update()
{


}

void Cortana::onTimerUpdate(lv_timer_t* timer)
{
	Cortana* instance = (Cortana*)timer->user_data;

	instance->Update();
}

void Cortana::onEvent(lv_event_t* event)
{
	lv_obj_t* obj = lv_event_get_target(event);
	lv_event_code_t code = lv_event_get_code(event);
	auto* instance = (Cortana*)lv_obj_get_user_data(obj);

	if (code == LV_EVENT_PRESSED)
	{
		if (lv_obj_has_state(obj, LV_STATE_FOCUSED))
		{
			instance->Manager->Push("Pages/Scene3D");
		}
	}

 
}
