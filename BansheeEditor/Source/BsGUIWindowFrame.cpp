#include "BsGUIWindowFrame.h"
#include "BsImageSprite.h"
#include "BsGUIWidget.h"
#include "BsGUISkin.h"
#include "BsSpriteTexture.h"
#include "BsGUIDimensions.h"
#include "BsGUIMouseEvent.h"
#include "BsCoreApplication.h"
#include "BsPlatform.h"
#include "BsTexture.h"
#include "BsRenderWindow.h"

namespace BansheeEngine
{
	const String& GUIWindowFrame::getGUITypeName()
	{
		static String name = "WindowFrame";
		return name;
	}

	GUIWindowFrame::GUIWindowFrame(const String& styleName, const GUIDimensions& layoutOptions)
		:GUITexture(styleName, HSpriteTexture(), GUIImageScaleMode::StretchToFit, true, layoutOptions)
	{

	}

	GUIWindowFrame::~GUIWindowFrame()
	{ }

	GUIWindowFrame* GUIWindowFrame::create(const String& styleName)
	{
		return new (bs_alloc<GUIWindowFrame, PoolAlloc>()) GUIWindowFrame(getStyleName<GUIWindowFrame>(styleName), GUIDimensions::create());
	}

	GUIWindowFrame* GUIWindowFrame::create(const GUIOptions& layoutOptions, const String& styleName)
	{
		return new (bs_alloc<GUIWindowFrame, PoolAlloc>()) GUIWindowFrame(getStyleName<GUIWindowFrame>(styleName), GUIDimensions::create(layoutOptions));
	}

	void GUIWindowFrame::setFocused(bool focused)
	{
		if(focused)
			mActiveTexture = _getStyle()->focused.texture;
		else
			mActiveTexture = _getStyle()->normal.texture;

		markContentAsDirty();
	}
}