#include "multithread_internal.h"

//==================================================================
//                             PRIVATE
//==================================================================

void uxr_lock_session(
        uxrSession* session)
{
#ifdef WIN32
#elif defined(PLATFORM_NAME_FREERTOS_PLUS_TCP)
#elif defined(UCLIENT_PLATFORM_ZEPHYR)
#else
    pthread_mutex_lock(&session->mutex.impl); 
#endif    
}

void uxr_unlock_session(
        uxrSession* session)
{
#ifdef WIN32
#elif defined(PLATFORM_NAME_FREERTOS_PLUS_TCP)
#elif defined(UCLIENT_PLATFORM_ZEPHYR)
#else
    pthread_mutex_unlock(&session->mutex.impl); 
#endif    
}
