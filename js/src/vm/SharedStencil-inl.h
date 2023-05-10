/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * vim: set ts=8 sts=2 et sw=2 tw=80:
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef vm_SharedStencil_inl_h
#define vm_SharedStencil_inl_h

#include "vm/SharedStencil.h"

#include "vm/BytecodeUtil.h"  // GET_RESUMEINDEX, JUMP_OFFSET_LEN

namespace js {

MOZ_ALWAYS_INLINE
uint32_t ImmutableScriptData::tableSwitchCaseOffset(jsbytecode* pc,
                                                    uint32_t caseIndex) {
  MOZ_ASSERT(JSOp(*pc) == JSOp::TableSwitch);
  uint32_t firstResumeIndex = GET_RESUMEINDEX(pc + 3 * JUMP_OFFSET_LEN);
  return resumeOffsets()[firstResumeIndex + caseIndex];
}
jsbytecode* ImmutableScriptData::tableSwitchCasePC(jsbytecode* pc,
                                                   uint32_t caseIndex) {
  return offsetToPC(tableSwitchCaseOffset(pc, caseIndex));
}
jsbytecode* ImmutableScriptData::offsetToPC(size_t offset) {
  return code() + offset;
}

size_t ImmutableScriptData::pcToOffset(const jsbytecode* pc) {
  return size_t(pc - code());
}

}  // namespace js

#endif /* vm_SharedStencil_inl_h */
