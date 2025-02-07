/**
 * \file dnn/src/arm_common/pooling/algo.h
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2021 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT ARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 */
#pragma once
#include "src/arm_common/pooling/opr_impl.h"
#include "src/arm_common/pooling/pooling_helper.h"
#include "src/common//utils.h"
#include "src/naive/handle.h"

namespace megdnn {
namespace arm_common {

using AlgoBase = PoolingImpl::AlgoBase;

class PoolingImpl::AlgoFilterxModexStride1 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_STRIDE1"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_FilterxModexStride1)
};

class PoolingImpl::AlgoFilter2ModexStride2 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_STRIDE2"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter2ModexStride2)
};
class PoolingImpl::AlgoFilter3MaxStride2 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER3_MAX"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter3MaxStride2)
};

class PoolingImpl::AlgoFilter3AverageStride2 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER3_AVERAGE"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter3AverageStride2)
};

class PoolingImpl::AlgoFilter4MaxStride2 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER4_MAX"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter4MaxStride2)
};

class PoolingImpl::AlgoFilter5MaxStride2 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER5_MAX"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter5MaxStride2)
};

class PoolingImpl::AlgoInt8Filter2MaxStride2 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_INT8_FILTER2X2"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Int8Filter2MaxStride2)
};

class PoolingImpl::AlgoInt8Filter3MaxStride2 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_INT8_FILTER3X3"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Int8Filter3MaxStride2)
};

class PoolingImpl::AlgoFilter3ModexStridexNCHW44 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER3_MODEX_STRIDEX_NCHW44"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter3ModexStridexNCHW44)
};

class PoolingImpl::AlgoFilter2ModexStridexNCHW44 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER2_MODEX_STRIDEX_NCHW44"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter2ModexStridexNCHW44)
};

class PoolingImpl::AlgoFilter4ModexStridexNCHW44 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER4_MODEX_STRIDEX_NCHW44"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter4ModexStridexNCHW44)
};

class PoolingImpl::AlgoFilter5ModexStridexNCHW44 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FILTER5_MODEX_STRIDEX_NCHW44"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Filter5ModexStridexNCHW44)
};
class PoolingImpl::AlgoFp32ModexStridexNCHW44 final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "ARM_POOLING_FP32_MODEX_STRIDEX_NCHW44"; }
    bool usable(const PoolingKernSizeParam& param) const override;
    void exec(const PoolingKernParam& param) const override;
    MEGDNN_DECL_ALGO_TYPE(ARM_Fp32ModexStridexNCHW44)
};
class PoolingImpl::AlgoFallback final : public AlgoBase {
public:
    AlgoAttribute attribute() const override {
        return AlgoAttribute::REPRODUCIBLE;
    };
    const char* name() const override { return "FALLBACK_POOLING"; }
    bool usable(const PoolingKernSizeParam&) const override { return true; }
    void exec(const PoolingKernParam&) const override {}
    MEGDNN_DECL_ALGO_TYPE(ARM_Fallback)
};
WorkspaceBundle get_bundle(const PoolingImpl::PoolingKernSizeParam& param);

WorkspaceBundle get_bundle_nchw44(
        const PoolingImpl::PoolingKernSizeParam& param);

const int8_t* handle_padding(const int8_t* src, size_t IH, size_t IW,
                             size_t& IH2, size_t& IW2, size_t PH, size_t PW,
                             const WorkspaceBundle& ws, bool is_max_mode);
}  // namespace arm_common
}  // namespace megdnn

// vim: syntax=cpp.doxygen

