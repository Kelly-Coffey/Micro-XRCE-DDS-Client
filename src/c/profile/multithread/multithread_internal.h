// Copyright 2021 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UXR_CLIENT_PROFILE_MULTITHREAD_INTERNAL_H_
#define UXR_CLIENT_PROFILE_MULTITHREAD_INTERNAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <uxr/client/config.h>

#include <uxr/client/visibility.h>
#include <uxr/client/core/session/session.h>

#ifdef UCLIENT_PROFILE_MULTITHREAD
#define UXR_LOCK_SESSION uxr_lock_session(session)
#define UXR_UNLOCK_SESSION uxr_unlock_session(session)
#else
#define UXR_LOCK_SESSION
#define UXR_UNLOCK_SESSION
#endif

/**
 * @brief
 * TODO
 */
UXRDLLAPI void uxr_lock_session(uxrSession* session);

/**
 * @brief
 * TODO
 */
UXRDLLAPI void uxr_unlock_session(uxrSession* session);

#ifdef __cplusplus
}
#endif

#endif // UXR_CLIENT_PROFILE_MULTITHREAD_INTERNAL_H_
