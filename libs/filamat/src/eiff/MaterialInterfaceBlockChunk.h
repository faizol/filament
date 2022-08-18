/*
 * Copyright (C) 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef TNT_FILAMAT_MAT_INTEFFACE_BLOCK_CHUNK_H
#define TNT_FILAMAT_MAT_INTEFFACE_BLOCK_CHUNK_H

#include "Chunk.h"

#include <private/filament/SamplerInterfaceBlock.h>
#include <private/filament/UniformInterfaceBlock.h>
#include <private/filament/SubpassInfo.h>

namespace filamat {

class MaterialUniformInterfaceBlockChunk final : public Chunk {
public:
    explicit MaterialUniformInterfaceBlockChunk(filament::UniformInterfaceBlock& uib);
    ~MaterialUniformInterfaceBlockChunk() final = default;

private:
    void flatten(Flattener &) final;

    filament::UniformInterfaceBlock& mUib;
};

class MaterialSamplerInterfaceBlockChunk final : public Chunk {
public:
    explicit MaterialSamplerInterfaceBlockChunk(filament::SamplerInterfaceBlock& sib);
    ~MaterialSamplerInterfaceBlockChunk() final = default;

private:
    void flatten(Flattener &) final;

    filament::SamplerInterfaceBlock& mSib;
};

class MaterialSubpassInterfaceBlockChunk final : public Chunk {
public:
    explicit MaterialSubpassInterfaceBlockChunk(filament::SubpassInfo& subpass);
    ~MaterialSubpassInterfaceBlockChunk() final = default;

private:
    void flatten(Flattener &) final;

    filament::SubpassInfo& mSubpass;
};

class MaterialUniformBlockBindingsChunk final : public Chunk {
public:
    explicit MaterialUniformBlockBindingsChunk(
            utils::FixedCapacityVector<std::pair<std::string_view, uint8_t>> list);
    ~MaterialUniformBlockBindingsChunk() final = default;

private:
    void flatten(Flattener &) final;

    utils::FixedCapacityVector<std::pair<std::string_view, uint8_t>> mBindingList;
};

} // namespace filamat

#endif // TNT_FILAMAT_MAT_INTEFFACE_BLOCK_CHUNK_H
