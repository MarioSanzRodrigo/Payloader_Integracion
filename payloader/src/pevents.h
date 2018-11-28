/* 
######################################################
    MODIFICACION PARA INTEGRACION EN ARQUEOPTERIX
######################################################
	        Payloader UPM - pevents
######################################################
*/

/*
 * WIN32 Events for POSIX
 * Author: Mahmoud Al-Qudsi <mqudsi@neosmart.net>
 * Copyright (C) 2011 - 2015 by NeoSmart Technologies
 * This code is released under the terms of the MIT License
*/

#pragma once

#if defined(_WIN32) && !defined(CreateEvent)
#error Must include Windows.h prior to including pevents.h!
#endif
#ifndef WAIT_TIMEOUT
#include <errno.h>
#define WAIT_TIMEOUT ETIMEDOUT
#endif
#ifndef WFMO
#define WFMO WFMO //triple, que es WFMO??
#endif

#include <stdint.h>

namespace payloader
{
	//Type declarations
	struct neosmart_event_t_;
	typedef neosmart_event_t_ * neosmart_event_t;
	
	//WIN32-style functions
	neosmart_event_t CreateEvent(bool manualReset = false, bool initialState = false);
	int DestroyEvent(neosmart_event_t event);
	int WaitForEvent(neosmart_event_t event, uint64_t milliseconds = -1);
	int SetEvent(neosmart_event_t event);
	int ResetEvent(neosmart_event_t event);
#ifdef WFMO
	int WaitForMultipleEvents(neosmart_event_t *events, int count, bool waitAll, uint64_t milliseconds);
	int WaitForMultipleEvents(neosmart_event_t *events, int count, bool waitAll, uint64_t milliseconds, int &index);
#endif
#ifdef PULSE
	int PulseEvent(neosmart_event_t event);
#endif
    
	//POSIX-style functions
	//TBD
}