/**
 * \file imperative/src/impl/interpreter/profiler.h
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2020 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

#pragma once

#include <unordered_set>

#include "megbrain/imperative/profiler.h"

#include "./states.h"

namespace mgb::imperative::profiler {

void dump_chrome_timeline(std::string filename, Profiler::bundle_t result);

void dump_memory_flow(std::string filename, Profiler::bundle_t result);

}
