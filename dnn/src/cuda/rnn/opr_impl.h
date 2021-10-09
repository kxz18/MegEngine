/**
 * \file dnn/src/cuda/rnn/opr_impl.h
 * MegEngine is Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Copyright (c) 2014-2021 Megvii Inc. All rights reserved.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * ARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */
#pragma once
#include "megdnn/oprs.h"
#include "src/cuda/cudnn_wrapper.h"
#include "src/cuda/rnn/utils.h"

namespace megdnn {
namespace cuda {

class RNNImpl : public RNN {
public:
    using RNN::RNN;

    void exec(
            _megdnn_tensor_in input, _megdnn_tensor_in hx,
            _megdnn_tensor_in flatten_weights, _megdnn_tensor_out output,
            _megdnn_tensor_out hy, _megdnn_tensor_out reserve_space,
            _megdnn_workspace workspace);

    size_t get_workspace_in_bytes(
            const TensorLayout& input, const TensorLayout& hx,
            const TensorLayout& flatten_weights, const TensorLayout& output,
            const TensorLayout& hy, const TensorLayout& reserve_space);
    size_t get_reserve_size_in_bytes(const TensorLayout& input);
    // private:
    //     rnn::RNNForwardDescHolder get_desc_holder(const TensorLayout& input);
};

class RNNBackwardImpl : public RNNBackward {
public:
    using RNNBackward::RNNBackward;

    virtual void exec(
            _megdnn_tensor_in x, _megdnn_tensor_in y, _megdnn_tensor_in hx,
            _megdnn_tensor_in dy, _megdnn_tensor_in dhy,
            _megdnn_tensor_in flatten_weights, _megdnn_tensor_in reserve_space,
            _megdnn_tensor_out dx, _megdnn_tensor_out dhx, _megdnn_tensor_out dw,
            _megdnn_workspace workspace);

    virtual size_t get_workspace_in_bytes(
            const TensorLayout& x, const TensorLayout& y, const TensorLayout& hx,
            const TensorLayout& dy, const TensorLayout& dhy,
            const TensorLayout& flatten_weights, const TensorLayout& reserve_space,
            const TensorLayout& dx, const TensorLayout& dhx, const TensorLayout& dw);
};

}  // namespace cuda
}  // namespace megdnn