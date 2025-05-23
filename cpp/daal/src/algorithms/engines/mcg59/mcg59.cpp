/* file: mcg59.cpp */
/*******************************************************************************
* Copyright 2014 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

//++
//  Implementation of mcg59 engine
//--

#include "algorithms/engines/mcg59/mcg59.h"
#include "src/externals/service_dispatch.h"
#include "src/algorithms/engines/mcg59/mcg59_batch_impl.h"

namespace daal
{
namespace algorithms
{
namespace engines
{
namespace mcg59
{
namespace interface1
{
using namespace daal::services;
using namespace mcg59::internal;

template <typename algorithmFPType, Method method>
SharedPtr<Batch<algorithmFPType, method> > Batch<algorithmFPType, method>::create(size_t seed)
{
    SharedPtr<Batch<algorithmFPType, method> > engPtr;
#define DAAL_CREATE_ENGINE_CPU(cpuId, ...) engPtr.reset(new BatchImpl<cpuId, algorithmFPType, method>(__VA_ARGS__));

    DAAL_DISPATCH_FUNCTION_BY_CPU(DAAL_CREATE_ENGINE_CPU, seed);

#undef DAAL_CREATE_ENGINE_CPU
    return engPtr;
}

template SharedPtr<Batch<double, defaultDense> > DAAL_EXPORT Batch<double, defaultDense>::create(size_t seed);
template SharedPtr<Batch<float, defaultDense> > DAAL_EXPORT Batch<float, defaultDense>::create(size_t seed);

} // namespace interface1
} // namespace mcg59
} // namespace engines
} // namespace algorithms
} // namespace daal
