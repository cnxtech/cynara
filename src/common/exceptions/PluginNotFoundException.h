/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */
/**
 * @file        src/common/exceptions/PluginNotFoundException.h
 * @author      Lukasz Wojciechowski <l.wojciechow@partner.samsung.com>
 * @version     1.0
 * @brief       Implementation of PluginNotFoundException
 */

#ifndef SRC_COMMON_EXCEPTIONS_PLUGINNOTFOUNDEXCEPTION_H_
#define SRC_COMMON_EXCEPTIONS_PLUGINNOTFOUNDEXCEPTION_H_

#include <exception>
#include <sstream>

#include <types/PolicyResult.h>
#include "Exception.h"

namespace Cynara {

class PluginNotFoundException : public Exception {
public:
    PluginNotFoundException() = delete;
    PluginNotFoundException(const PolicyResult &result) {
        m_message = "No proper plugin found to interprete PolicyResult {type = ["
                  + std::to_string(result.policyType()) + "], metadata = <"
                  + result.metadata().substr(0, 20) + ">}";
    }

    virtual ~PluginNotFoundException() {};

    virtual const std::string &message(void) const {
        return m_message;
    }

private:
    std::string m_message;
};

} // namespace Cynara

#endif /* SRC_COMMON_EXCEPTIONS_PLUGINNOTFOUNDEXCEPTION_H_ */
