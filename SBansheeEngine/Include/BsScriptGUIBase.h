#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptObject.h"

namespace BansheeEngine
{
	class BS_SCR_BE_EXPORT ScriptGUIBaseMeta : public ScriptObject<ScriptGUIBaseMeta>
	{
	public:
		friend class ScriptGUIBase;

		static void initMetaData();
	};

	class BS_SCR_BE_EXPORT ScriptGUIBase
	{
	public:
		virtual GUIWidget& getWidget() const = 0;

		static void initRuntimeData() { }

		static ScriptGUIBase* toNative(MonoObject* managedInstance)
		{
			ScriptGUIBase* nativeInstance = nullptr;
			ScriptGUIBaseMeta::metaData.thisPtrField->getValue(managedInstance, &nativeInstance);

			return nativeInstance;
		}

	protected:
		ScriptGUIBase();
	};
}