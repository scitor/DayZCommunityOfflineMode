class ActionCloseBarrelHoles: ActionInteractBase
{
	void ActionCloseBarrelHoles()
	{
		m_MessageSuccess = "I have closed it.";
		//m_Animation = "close";
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_CLOSELID;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}

	override int GetType()
	{
		return AT_CLOSE_BARREL_HOLES;
	}

	override string GetText()
	{
		return "close";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		if ( target_object.IsItemBase() )
		{
			BarrelHoles_ColorBase ntarget = BarrelHoles_ColorBase.Cast( target_object );
			if( ntarget )
			{			
				if ( ntarget.IsOpened() )
				{
					return true;
				}
			}
		}
		return false;
	}

	override void OnCompleteServer( PlayerBase player, ActionTarget target, ItemBase item, Param acdata )
	{
		Object target_object = target.GetObject();
		BarrelHoles_ColorBase ntarget = BarrelHoles_ColorBase.Cast( target_object );
		if( ntarget )
		{
			ntarget.Close();
		}
	}
}