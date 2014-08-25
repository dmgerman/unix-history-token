begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_REGISTER_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_REGISTER_H_
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQBAH
value|0x000801C0
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ARQBAH_ARQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQBAH_ARQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_ARQBAH_ARQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQBAL
value|0x000800C0
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ARQBAL_ARQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQBAL_ARQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_ARQBAL_ARQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQH
value|0x000803C0
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ARQH_ARQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQH_ARQH_MASK
value|I40E_MASK(0x3FF, I40E_GL_ARQH_ARQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQT
value|0x000804C0
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ARQT_ARQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ARQT_ARQT_MASK
value|I40E_MASK(0x3FF, I40E_GL_ARQT_ARQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQBAH
value|0x00080140
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ATQBAH_ATQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQBAH_ATQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_ATQBAH_ATQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQBAL
value|0x00080040
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ATQBAL_ATQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQBAL_ATQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_ATQBAL_ATQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQH
value|0x00080340
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ATQH_ATQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQH_ATQH_MASK
value|I40E_MASK(0x3FF, I40E_GL_ATQH_ATQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN
value|0x00080240
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQLEN_MASK
value|I40E_MASK(0x3FF, I40E_GL_ATQLEN_ATQLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQVFE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQVFE_MASK
value|I40E_MASK(0x1, I40E_GL_ATQLEN_ATQVFE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQOVFL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQOVFL_MASK
value|I40E_MASK(0x1, I40E_GL_ATQLEN_ATQOVFL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQCRIT_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQCRIT_MASK
value|I40E_MASK(0x1, I40E_GL_ATQLEN_ATQCRIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQENABLE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQLEN_ATQENABLE_MASK
value|I40E_MASK(0x1, I40E_GL_ATQLEN_ATQENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQT
value|0x00080440
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_ATQT_ATQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_ATQT_ATQT_MASK
value|I40E_MASK(0x3FF, I40E_GL_ATQT_ATQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQBAH
value|0x00080180
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ARQBAH_ARQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQBAH_ARQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PF_ARQBAH_ARQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQBAL
value|0x00080080
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ARQBAL_ARQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQBAL_ARQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PF_ARQBAL_ARQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQH
value|0x00080380
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ARQH_ARQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQH_ARQH_MASK
value|I40E_MASK(0x3FF, I40E_PF_ARQH_ARQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN
value|0x00080280
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQLEN_MASK
value|I40E_MASK(0x3FF, I40E_PF_ARQLEN_ARQLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQVFE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQVFE_MASK
value|I40E_MASK(0x1, I40E_PF_ARQLEN_ARQVFE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQOVFL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQOVFL_MASK
value|I40E_MASK(0x1, I40E_PF_ARQLEN_ARQOVFL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQCRIT_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQCRIT_MASK
value|I40E_MASK(0x1, I40E_PF_ARQLEN_ARQCRIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQENABLE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQLEN_ARQENABLE_MASK
value|I40E_MASK(0x1, I40E_PF_ARQLEN_ARQENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQT
value|0x00080480
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ARQT_ARQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ARQT_ARQT_MASK
value|I40E_MASK(0x3FF, I40E_PF_ARQT_ARQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQBAH
value|0x00080100
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ATQBAH_ATQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQBAH_ATQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PF_ATQBAH_ATQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQBAL
value|0x00080000
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ATQBAL_ATQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQBAL_ATQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PF_ATQBAL_ATQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQH
value|0x00080300
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ATQH_ATQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQH_ATQH_MASK
value|I40E_MASK(0x3FF, I40E_PF_ATQH_ATQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN
value|0x00080200
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQLEN_MASK
value|I40E_MASK(0x3FF, I40E_PF_ATQLEN_ATQLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQVFE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQVFE_MASK
value|I40E_MASK(0x1, I40E_PF_ATQLEN_ATQVFE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQOVFL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQOVFL_MASK
value|I40E_MASK(0x1, I40E_PF_ATQLEN_ATQOVFL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQCRIT_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQCRIT_MASK
value|I40E_MASK(0x1, I40E_PF_ATQLEN_ATQCRIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQENABLE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQLEN_ATQENABLE_MASK
value|I40E_MASK(0x1, I40E_PF_ATQLEN_ATQENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQT
value|0x00080400
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_ATQT_ATQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_ATQT_ATQT_MASK
value|I40E_MASK(0x3FF, I40E_PF_ATQT_ATQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAH
parameter_list|(
name|_VF
parameter_list|)
value|(0x00081400 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQBAH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAH_ARQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAH_ARQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ARQBAH_ARQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAL
parameter_list|(
name|_VF
parameter_list|)
value|(0x00080C00 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQBAL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAL_ARQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAL_ARQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ARQBAL_ARQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQH
parameter_list|(
name|_VF
parameter_list|)
value|(0x00082400 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQH_ARQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQH_ARQH_MASK
value|I40E_MASK(0x3FF, I40E_VF_ARQH_ARQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN
parameter_list|(
name|_VF
parameter_list|)
value|(0x00081C00 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQLEN_MASK
value|I40E_MASK(0x3FF, I40E_VF_ARQLEN_ARQLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQVFE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQVFE_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN_ARQVFE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQOVFL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQOVFL_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN_ARQOVFL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQCRIT_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQCRIT_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN_ARQCRIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQENABLE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN_ARQENABLE_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN_ARQENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQT
parameter_list|(
name|_VF
parameter_list|)
value|(0x00082C00 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQT_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQT_ARQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQT_ARQT_MASK
value|I40E_MASK(0x3FF, I40E_VF_ARQT_ARQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAH
parameter_list|(
name|_VF
parameter_list|)
value|(0x00081000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQBAH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAH_ATQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAH_ATQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ATQBAH_ATQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAL
parameter_list|(
name|_VF
parameter_list|)
value|(0x00080800 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQBAL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAL_ATQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAL_ATQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ATQBAL_ATQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQH
parameter_list|(
name|_VF
parameter_list|)
value|(0x00082000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQH_ATQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQH_ATQH_MASK
value|I40E_MASK(0x3FF, I40E_VF_ATQH_ATQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN
parameter_list|(
name|_VF
parameter_list|)
value|(0x00081800 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQLEN_MASK
value|I40E_MASK(0x3FF, I40E_VF_ATQLEN_ATQLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQVFE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQVFE_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN_ATQVFE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQOVFL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQOVFL_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN_ATQOVFL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQCRIT_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQCRIT_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN_ATQCRIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQENABLE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN_ATQENABLE_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN_ATQENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQT
parameter_list|(
name|_VF
parameter_list|)
value|(0x00082800 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQT_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQT_ATQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQT_ATQT_MASK
value|I40E_MASK(0x3FF, I40E_VF_ATQT_ATQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_L2TAGSEN
value|0x001C0B20
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_L2TAGSEN_ENABLE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_L2TAGSEN_ENABLE_MASK
value|I40E_MASK(0xFF, I40E_PRT_L2TAGSEN_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRDATA
value|0x0010C080
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRDATA_ERROR_CODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRDATA_ERROR_CODE_MASK
value|I40E_MASK(0xF, I40E_PFCM_LAN_ERRDATA_ERROR_CODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRDATA_Q_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRDATA_Q_TYPE_MASK
value|I40E_MASK(0x7, I40E_PFCM_LAN_ERRDATA_Q_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRDATA_Q_NUM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRDATA_Q_NUM_MASK
value|I40E_MASK(0xFFF, I40E_PFCM_LAN_ERRDATA_Q_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO
value|0x0010C000
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_ERROR_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_ERROR_VALID_MASK
value|I40E_MASK(0x1, I40E_PFCM_LAN_ERRINFO_ERROR_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_ERROR_INST_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_ERROR_INST_MASK
value|I40E_MASK(0x7, I40E_PFCM_LAN_ERRINFO_ERROR_INST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_DBL_ERROR_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_DBL_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_PFCM_LAN_ERRINFO_DBL_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_RLU_ERROR_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_RLU_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_PFCM_LAN_ERRINFO_RLU_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_RLS_ERROR_CNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LAN_ERRINFO_RLS_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_PFCM_LAN_ERRINFO_RLS_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL
value|0x0010C300
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_QUEUE_NUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_QUEUE_NUM_MASK
value|I40E_MASK(0xFFF, I40E_PFCM_LANCTXCTL_QUEUE_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_SUB_LINE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_SUB_LINE_MASK
value|I40E_MASK(0x7, I40E_PFCM_LANCTXCTL_SUB_LINE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_QUEUE_TYPE_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_QUEUE_TYPE_MASK
value|I40E_MASK(0x3, I40E_PFCM_LANCTXCTL_QUEUE_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_OP_CODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXCTL_OP_CODE_MASK
value|I40E_MASK(0x3, I40E_PFCM_LANCTXCTL_OP_CODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXDATA
parameter_list|(
name|_i
parameter_list|)
value|(0x0010C100 + ((_i) * 128))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXDATA_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXDATA_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXDATA_DATA_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PFCM_LANCTXDATA_DATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXSTAT
value|0x0010C380
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXSTAT_CTX_DONE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXSTAT_CTX_DONE_MASK
value|I40E_MASK(0x1, I40E_PFCM_LANCTXSTAT_CTX_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXSTAT_CTX_MISS_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFCM_LANCTXSTAT_CTX_MISS_MASK
value|I40E_MASK(0x1, I40E_PFCM_LANCTXSTAT_CTX_MISS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1
parameter_list|(
name|_VF
parameter_list|)
value|(0x00138800 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1_ERROR_CODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1_ERROR_CODE_MASK
value|I40E_MASK(0xF, I40E_VFCM_PE_ERRDATA1_ERROR_CODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1_Q_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1_Q_TYPE_MASK
value|I40E_MASK(0x7, I40E_VFCM_PE_ERRDATA1_Q_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1_Q_NUM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA1_Q_NUM_MASK
value|I40E_MASK(0x3FFFF, I40E_VFCM_PE_ERRDATA1_Q_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1
parameter_list|(
name|_VF
parameter_list|)
value|(0x00138400 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_ERROR_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_ERROR_VALID_MASK
value|I40E_MASK(0x1, I40E_VFCM_PE_ERRINFO1_ERROR_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_ERROR_INST_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_ERROR_INST_MASK
value|I40E_MASK(0x7, I40E_VFCM_PE_ERRINFO1_ERROR_INST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_DBL_ERROR_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_DBL_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO1_DBL_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_RLU_ERROR_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_RLU_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO1_RLU_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_RLS_ERROR_CNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO1_RLS_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO1_RLS_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLDCB_GENC
value|0x00083044
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLDCB_GENC_PCIRTT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLDCB_GENC_PCIRTT_MASK
value|I40E_MASK(0xFFFF, I40E_GLDCB_GENC_PCIRTT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLDCB_RUPTI
value|0x00122618
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLDCB_RUPTI_PFCTIMEOUT_UP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLDCB_RUPTI_PFCTIMEOUT_UP_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLDCB_RUPTI_PFCTIMEOUT_UP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCCFG
value|0x001E4640
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCCFG_TFCE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCCFG_TFCE_MASK
value|I40E_MASK(0x3, I40E_PRTDCB_FCCFG_TFCE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCRTV
value|0x001E4600
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCRTV_FC_REFRESH_TH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCRTV_FC_REFRESH_TH_MASK
value|I40E_MASK(0xFFFF, I40E_PRTDCB_FCRTV_FC_REFRESH_TH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCTTVN
parameter_list|(
name|_i
parameter_list|)
value|(0x001E4580 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCTTVN_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCTTVN_TTV_2N_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCTTVN_TTV_2N_MASK
value|I40E_MASK(0xFFFF, I40E_PRTDCB_FCTTVN_TTV_2N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCTTVN_TTV_2N_P1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_FCTTVN_TTV_2N_P1_MASK
value|I40E_MASK(0xFFFF, I40E_PRTDCB_FCTTVN_TTV_2N_P1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC
value|0x00083000
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_RESERVED_1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_RESERVED_1_MASK
value|I40E_MASK(0x3, I40E_PRTDCB_GENC_RESERVED_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_NUMTC_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_NUMTC_MASK
value|I40E_MASK(0xF, I40E_PRTDCB_GENC_NUMTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_FCOEUP_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_FCOEUP_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_GENC_FCOEUP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_FCOEUP_VALID_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_FCOEUP_VALID_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_GENC_FCOEUP_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_PFCLDA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENC_PFCLDA_MASK
value|I40E_MASK(0xFFFF, I40E_PRTDCB_GENC_PFCLDA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENS
value|0x00083020
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENS_DCBX_STATUS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_GENS_DCBX_STATUS_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_GENS_DCBX_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN
value|0x001E2400
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_PMCF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_PMCF_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_MFLCN_PMCF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_DPF_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_DPF_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_MFLCN_DPF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_RPFCM_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_RPFCM_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_MFLCN_RPFCM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_RFCE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_RFCE_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_MFLCN_RFCE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_RPFCE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_MFLCN_RPFCE_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_MFLCN_RPFCE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC
value|0x001223E0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_ETS_MODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_ETS_MODE_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_RETSC_ETS_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_NON_ETS_MODE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_NON_ETS_MODE_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_RETSC_NON_ETS_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_ETS_MAX_EXP_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_ETS_MAX_EXP_MASK
value|I40E_MASK(0xF, I40E_PRTDCB_RETSC_ETS_MAX_EXP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_LLTC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSC_LLTC_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_RETSC_LLTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC
parameter_list|(
name|_i
parameter_list|)
value|(0x00122180 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC_BWSHARE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC_BWSHARE_MASK
value|I40E_MASK(0x7F, I40E_PRTDCB_RETSTCC_BWSHARE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC_UPINTC_MODE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC_UPINTC_MODE_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_RETSTCC_UPINTC_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC_ETSTC_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RETSTCC_ETSTC_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_RETSTCC_ETSTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RPPMC
value|0x001223A0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_RPPMC_LANRPPM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RPPMC_LANRPPM_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_RPPMC_LANRPPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RPPMC_RDMARPPM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RPPMC_RDMARPPM_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_RPPMC_RDMARPPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RPPMC_RX_FIFO_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RPPMC_RX_FIFO_SIZE_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_RPPMC_RX_FIFO_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP
value|0x001C0B00
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP_NOVLANUP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP_NOVLANUP_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP_NOVLANUP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC
value|0x001C09A0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP0TC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP0TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP0TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP1TC_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP1TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP1TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP2TC_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP2TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP2TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP3TC_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP3TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP3TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP4TC_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP4TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP4TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP5TC_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP5TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP5TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP6TC_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP6TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP6TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP7TC_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_RUP2TC_UP7TC_MASK
value|I40E_MASK(0x7, I40E_PRTDCB_RUP2TC_UP7TC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TC2PFC
value|0x001C0980
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TC2PFC_TC2PFC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TC2PFC_TC2PFC_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_TC2PFC_TC2PFC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCMSTC
parameter_list|(
name|_i
parameter_list|)
value|(0x000A0040 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCMSTC_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCMSTC_MSTC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCMSTC_MSTC_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTDCB_TCMSTC_MSTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCPMC
value|0x000A21A0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCPMC_CPM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCPMC_CPM_MASK
value|I40E_MASK(0x1FFF, I40E_PRTDCB_TCPMC_CPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCPMC_LLTC_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCPMC_LLTC_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_TCPMC_LLTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCPMC_TCPM_MODE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCPMC_TCPM_MODE_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TCPMC_TCPM_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCWSTC
parameter_list|(
name|_i
parameter_list|)
value|(0x000A2040 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCWSTC_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCWSTC_MSTC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TCWSTC_MSTC_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTDCB_TCWSTC_MSTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TDPMC
value|0x000A0180
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TDPMC_DPM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TDPMC_DPM_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_TDPMC_DPM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TDPMC_TCPM_MODE_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TDPMC_TCPM_MODE_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TDPMC_TCPM_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TCB
value|0x000AE060
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TCB_EN_LL_STRICT_PRIORITY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TCB_EN_LL_STRICT_PRIORITY_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TETSC_TCB_EN_LL_STRICT_PRIORITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TCB_LLTC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TCB_LLTC_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_TETSC_TCB_LLTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TPB
value|0x00098060
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TPB_EN_LL_STRICT_PRIORITY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TPB_EN_LL_STRICT_PRIORITY_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TETSC_TPB_EN_LL_STRICT_PRIORITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TPB_LLTC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TETSC_TPB_LLTC_MASK
value|I40E_MASK(0xFF, I40E_PRTDCB_TETSC_TPB_LLTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS
value|0x001E4560
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF0_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF0_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF1_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF1_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF2_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF2_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF3_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF3_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF4_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF4_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF5_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF5_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF6_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF6_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF7_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TFCS_TXOFF7_MASK
value|I40E_MASK(0x1, I40E_PRTDCB_TFCS_TXOFF7_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TPFCTS
parameter_list|(
name|_i
parameter_list|)
value|(0x001E4660 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTDCB_TPFCTS_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TPFCTS_PFCTIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTDCB_TPFCTS_PFCTIMER_MASK
value|I40E_MASK(0x3FFF, I40E_PRTDCB_TPFCTS_PFCTIMER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL
value|0x00269B94
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_FCOEVER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_FCOEVER_MASK
value|I40E_MASK(0xF, I40E_GLFCOE_RCTL_FCOEVER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_SAVBAD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_SAVBAD_MASK
value|I40E_MASK(0x1, I40E_GLFCOE_RCTL_SAVBAD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_ICRC_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_ICRC_MASK
value|I40E_MASK(0x1, I40E_GLFCOE_RCTL_ICRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_MAX_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLFCOE_RCTL_MAX_SIZE_MASK
value|I40E_MASK(0x3FFF, I40E_GLFCOE_RCTL_MAX_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWSTS
value|0x00083048
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FWSTS_FWS0B_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWSTS_FWS0B_MASK
value|I40E_MASK(0xFF, I40E_GL_FWSTS_FWS0B_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWSTS_FWRI_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWSTS_FWRI_MASK
value|I40E_MASK(0x1, I40E_GL_FWSTS_FWRI_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWSTS_FWS1B_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWSTS_FWS1B_MASK
value|I40E_MASK(0xFF, I40E_GL_FWSTS_FWS1B_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT
value|0x000B8184
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_CLKMODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_CLKMODE_MASK
value|I40E_MASK(0x1, I40E_GLGEN_CLKSTAT_CLKMODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_U_CLK_SPEED_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_U_CLK_SPEED_MASK
value|I40E_MASK(0x3, I40E_GLGEN_CLKSTAT_U_CLK_SPEED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P0_CLK_SPEED_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P0_CLK_SPEED_MASK
value|I40E_MASK(0x7, I40E_GLGEN_CLKSTAT_P0_CLK_SPEED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P1_CLK_SPEED_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P1_CLK_SPEED_MASK
value|I40E_MASK(0x7, I40E_GLGEN_CLKSTAT_P1_CLK_SPEED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P2_CLK_SPEED_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P2_CLK_SPEED_MASK
value|I40E_MASK(0x7, I40E_GLGEN_CLKSTAT_P2_CLK_SPEED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P3_CLK_SPEED_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_CLKSTAT_P3_CLK_SPEED_MASK
value|I40E_MASK(0x7, I40E_GLGEN_CLKSTAT_P3_CLK_SPEED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL
parameter_list|(
name|_i
parameter_list|)
value|(0x00088100 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...29 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_MAX_INDEX
value|29
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PRT_NUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PRT_NUM_MASK
value|I40E_MASK(0x3, I40E_GLGEN_GPIO_CTL_PRT_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PRT_NUM_NA_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PRT_NUM_NA_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_CTL_PRT_NUM_NA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PIN_DIR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PIN_DIR_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_CTL_PIN_DIR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_TRI_CTL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_TRI_CTL_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_CTL_TRI_CTL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_OUT_CTL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_OUT_CTL_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_CTL_OUT_CTL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PIN_FUNC_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PIN_FUNC_MASK
value|I40E_MASK(0x7, I40E_GLGEN_GPIO_CTL_PIN_FUNC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_LED_INVRT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_LED_INVRT_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_CTL_LED_INVRT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_LED_BLINK_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_LED_BLINK_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_CTL_LED_BLINK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_LED_MODE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_LED_MODE_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_GPIO_CTL_LED_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_INT_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_INT_MODE_MASK
value|I40E_MASK(0x3, I40E_GLGEN_GPIO_CTL_INT_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_OUT_DEFAULT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_OUT_DEFAULT_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_CTL_OUT_DEFAULT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PHY_PIN_NAME_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_CTL_PHY_PIN_NAME_MASK
value|I40E_MASK(0x3F, I40E_GLGEN_GPIO_CTL_PHY_PIN_NAME_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_SET
value|0x00088184
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_SET_GPIO_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_SET_GPIO_INDX_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_GPIO_SET_GPIO_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_SET_SDP_DATA_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_SET_SDP_DATA_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_SET_SDP_DATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_SET_DRIVE_SDP_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_SET_DRIVE_SDP_MASK
value|I40E_MASK(0x1, I40E_GLGEN_GPIO_SET_DRIVE_SDP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_STAT
value|0x0008817C
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_STAT_GPIO_VALUE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_STAT_GPIO_VALUE_MASK
value|I40E_MASK(0x3FFFFFFF, I40E_GLGEN_GPIO_STAT_GPIO_VALUE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_TRANSIT
value|0x00088180
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_TRANSIT_GPIO_TRANSITION_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_GPIO_TRANSIT_GPIO_TRANSITION_MASK
value|I40E_MASK(0x3FFFFFFF, I40E_GLGEN_GPIO_TRANSIT_GPIO_TRANSITION_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD
parameter_list|(
name|_i
parameter_list|)
value|(0x000881E0 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_DATA_MASK
value|I40E_MASK(0xFFFF, I40E_GLGEN_I2CCMD_DATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_REGADD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_REGADD_MASK
value|I40E_MASK(0xFF, I40E_GLGEN_I2CCMD_REGADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_PHYADD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_PHYADD_MASK
value|I40E_MASK(0x7, I40E_GLGEN_I2CCMD_PHYADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_OP_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_OP_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CCMD_OP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_RESET_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_RESET_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CCMD_RESET_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_R_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_R_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CCMD_R_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_E_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CCMD_E_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CCMD_E_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS
parameter_list|(
name|_i
parameter_list|)
value|(0x000881AC + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_WRITE_TIME_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_WRITE_TIME_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_I2CPARAMS_WRITE_TIME_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_READ_TIME_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_READ_TIME_MASK
value|I40E_MASK(0x7, I40E_GLGEN_I2CPARAMS_READ_TIME_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_I2CBB_EN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_I2CBB_EN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_I2CBB_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_CLK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_DATA_OUT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_DATA_OUT_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_DATA_OUT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_DATA_OE_N_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_DATA_OE_N_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_DATA_OE_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_DATA_IN_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_DATA_IN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_DATA_IN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_OE_N_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_OE_N_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_CLK_OE_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_IN_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_IN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_CLK_IN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_STRETCH_DIS_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_CLK_STRETCH_DIS_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_CLK_STRETCH_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_I2C_DATA_ORDER_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_I2CPARAMS_I2C_DATA_ORDER_MASK
value|I40E_MASK(0x1, I40E_GLGEN_I2CPARAMS_I2C_DATA_ORDER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_LED_CTL
value|0x00088178
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_LED_CTL_GLOBAL_BLINK_MODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_LED_CTL_GLOBAL_BLINK_MODE_MASK
value|I40E_MASK(0x1, I40E_GLGEN_LED_CTL_GLOBAL_BLINK_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL
parameter_list|(
name|_i
parameter_list|)
value|(0x000881D0 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL_LEGACY_RSVD2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL_LEGACY_RSVD2_MASK
value|I40E_MASK(0x1FFFF, I40E_GLGEN_MDIO_CTRL_LEGACY_RSVD2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL_CONTMDC_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL_CONTMDC_MASK
value|I40E_MASK(0x1, I40E_GLGEN_MDIO_CTRL_CONTMDC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL_LEGACY_RSVD1_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_CTRL_LEGACY_RSVD1_MASK
value|I40E_MASK(0x3FFF, I40E_GLGEN_MDIO_CTRL_LEGACY_RSVD1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL
parameter_list|(
name|_i
parameter_list|)
value|(0x000881C0 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_MDIO_I2C_SEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_MDIO_I2C_SEL_MASK
value|I40E_MASK(0x1, I40E_GLGEN_MDIO_I2C_SEL_MDIO_I2C_SEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY_PORT_NUM_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY_PORT_NUM_MASK
value|I40E_MASK(0xF, I40E_GLGEN_MDIO_I2C_SEL_PHY_PORT_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY0_ADDRESS_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY0_ADDRESS_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_MDIO_I2C_SEL_PHY0_ADDRESS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY1_ADDRESS_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY1_ADDRESS_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_MDIO_I2C_SEL_PHY1_ADDRESS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY2_ADDRESS_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY2_ADDRESS_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_MDIO_I2C_SEL_PHY2_ADDRESS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY3_ADDRESS_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_PHY3_ADDRESS_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_MDIO_I2C_SEL_PHY3_ADDRESS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_MDIO_IF_MODE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_MDIO_IF_MODE_MASK
value|I40E_MASK(0xF, I40E_GLGEN_MDIO_I2C_SEL_MDIO_IF_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_EN_FAST_MODE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MDIO_I2C_SEL_EN_FAST_MODE_MASK
value|I40E_MASK(0x1, I40E_GLGEN_MDIO_I2C_SEL_EN_FAST_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA
parameter_list|(
name|_i
parameter_list|)
value|(0x0008818C + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_MDIADD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_MDIADD_MASK
value|I40E_MASK(0xFFFF, I40E_GLGEN_MSCA_MDIADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_DEVADD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_DEVADD_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_MSCA_DEVADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_PHYADD_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_PHYADD_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_MSCA_PHYADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_OPCODE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_OPCODE_MASK
value|I40E_MASK(0x3, I40E_GLGEN_MSCA_OPCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_STCODE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_STCODE_MASK
value|I40E_MASK(0x3, I40E_GLGEN_MSCA_STCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_MDICMD_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_MDICMD_MASK
value|I40E_MASK(0x1, I40E_GLGEN_MSCA_MDICMD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_MDIINPROGEN_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSCA_MDIINPROGEN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_MSCA_MDIINPROGEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSRWD
parameter_list|(
name|_i
parameter_list|)
value|(0x0008819C + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_MSRWD_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSRWD_MDIWRDATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSRWD_MDIWRDATA_MASK
value|I40E_MASK(0xFFFF, I40E_GLGEN_MSRWD_MDIWRDATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSRWD_MDIRDDATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_MSRWD_MDIRDDATA_MASK
value|I40E_MASK(0xFFFF, I40E_GLGEN_MSRWD_MDIRDDATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_PCIFCNCNT
value|0x001C0AB4
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_PCIFCNCNT_PCIPFCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_PCIFCNCNT_PCIPFCNT_MASK
value|I40E_MASK(0x1F, I40E_GLGEN_PCIFCNCNT_PCIPFCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_PCIFCNCNT_PCIVFCNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_PCIFCNCNT_PCIVFCNT_MASK
value|I40E_MASK(0xFF, I40E_GLGEN_PCIFCNCNT_PCIVFCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT
value|0x000B8188
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_DEVSTATE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_DEVSTATE_MASK
value|I40E_MASK(0x3, I40E_GLGEN_RSTAT_DEVSTATE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_RESET_TYPE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_RESET_TYPE_MASK
value|I40E_MASK(0x3, I40E_GLGEN_RSTAT_RESET_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_CORERCNT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_CORERCNT_MASK
value|I40E_MASK(0x3, I40E_GLGEN_RSTAT_CORERCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_GLOBRCNT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_GLOBRCNT_MASK
value|I40E_MASK(0x3, I40E_GLGEN_RSTAT_GLOBRCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_EMPRCNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_EMPRCNT_MASK
value|I40E_MASK(0x3, I40E_GLGEN_RSTAT_EMPRCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_TIME_TO_RST_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTAT_TIME_TO_RST_MASK
value|I40E_MASK(0x3F, I40E_GLGEN_RSTAT_TIME_TO_RST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTCTL
value|0x000B8180
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTCTL_GRSTDEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTCTL_GRSTDEL_MASK
value|I40E_MASK(0x3F, I40E_GLGEN_RSTCTL_GRSTDEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTCTL_ECC_RST_ENA_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTCTL_ECC_RST_ENA_MASK
value|I40E_MASK(0x1, I40E_GLGEN_RSTCTL_ECC_RST_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTENA_EMP
value|0x000B818C
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTENA_EMP_EMP_RST_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RSTENA_EMP_EMP_RST_ENA_MASK
value|I40E_MASK(0x1, I40E_GLGEN_RSTENA_EMP_EMP_RST_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RTRIG
value|0x000B8190
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_RTRIG_CORER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RTRIG_CORER_MASK
value|I40E_MASK(0x1, I40E_GLGEN_RTRIG_CORER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RTRIG_GLOBR_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RTRIG_GLOBR_MASK
value|I40E_MASK(0x1, I40E_GLGEN_RTRIG_GLOBR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RTRIG_EMPFWR_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_RTRIG_EMPFWR_MASK
value|I40E_MASK(0x1, I40E_GLGEN_RTRIG_EMPFWR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT
value|0x000B612C
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_HWRSVD0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_HWRSVD0_MASK
value|I40E_MASK(0x3, I40E_GLGEN_STAT_HWRSVD0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_DCBEN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_DCBEN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_STAT_DCBEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_VTEN_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_VTEN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_STAT_VTEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_FCOEN_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_FCOEN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_STAT_FCOEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_EVBEN_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_EVBEN_MASK
value|I40E_MASK(0x1, I40E_GLGEN_STAT_EVBEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_HWRSVD1_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_STAT_HWRSVD1_MASK
value|I40E_MASK(0x3, I40E_GLGEN_STAT_HWRSVD1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_VFLRSTAT
parameter_list|(
name|_i
parameter_list|)
value|(0x00092600 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLGEN_VFLRSTAT_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_VFLRSTAT_VFLRE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLGEN_VFLRSTAT_VFLRE_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLGEN_VFLRSTAT_VFLRE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVFGEN_TIMER
value|0x000881BC
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVFGEN_TIMER_GTIME_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVFGEN_TIMER_GTIME_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVFGEN_TIMER_GTIME_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_CTRL
value|0x00092400
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFGEN_CTRL_PFSWR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_CTRL_PFSWR_MASK
value|I40E_MASK(0x1, I40E_PFGEN_CTRL_PFSWR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_DRUN
value|0x00092500
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFGEN_DRUN_DRVUNLD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_DRUN_DRVUNLD_MASK
value|I40E_MASK(0x1, I40E_PFGEN_DRUN_DRVUNLD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTNUM
value|0x001C0480
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTNUM_PORT_NUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTNUM_PORT_NUM_MASK
value|I40E_MASK(0x3, I40E_PFGEN_PORTNUM_PORT_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE
value|0x00088000
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_RESERVED_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_RESERVED_0_MASK
value|I40E_MASK(0x1, I40E_PFGEN_STATE_RESERVED_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_PFFCEN_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_PFFCEN_MASK
value|I40E_MASK(0x1, I40E_PFGEN_STATE_PFFCEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_PFLINKEN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_PFLINKEN_MASK
value|I40E_MASK(0x1, I40E_PFGEN_STATE_PFLINKEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_PFSCEN_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_STATE_PFSCEN_MASK
value|I40E_MASK(0x1, I40E_PFGEN_STATE_PFSCEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF
value|0x000B8120
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF_PORT_DIS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF_PORT_DIS_MASK
value|I40E_MASK(0x1, I40E_PRTGEN_CNF_PORT_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF_ALLOW_PORT_DIS_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF_ALLOW_PORT_DIS_MASK
value|I40E_MASK(0x1, I40E_PRTGEN_CNF_ALLOW_PORT_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF_EMP_PORT_DIS_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF_EMP_PORT_DIS_MASK
value|I40E_MASK(0x1, I40E_PRTGEN_CNF_EMP_PORT_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF2
value|0x000B8160
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF2_ACTIVATE_PORT_LINK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_CNF2_ACTIVATE_PORT_LINK_MASK
value|I40E_MASK(0x1, I40E_PRTGEN_CNF2_ACTIVATE_PORT_LINK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_STATUS
value|0x000B8100
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTGEN_STATUS_PORT_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_STATUS_PORT_VALID_MASK
value|I40E_MASK(0x1, I40E_PRTGEN_STATUS_PORT_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_STATUS_PORT_ACTIVE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTGEN_STATUS_PORT_ACTIVE_MASK
value|I40E_MASK(0x1, I40E_PRTGEN_STATUS_PORT_ACTIVE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFGEN_RSTAT1
parameter_list|(
name|_VF
parameter_list|)
value|(0x00074400 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFGEN_RSTAT1_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VFGEN_RSTAT1_VFR_STATE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFGEN_RSTAT1_VFR_STATE_MASK
value|I40E_MASK(0x3, I40E_VFGEN_RSTAT1_VFR_STATE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRSTAT
parameter_list|(
name|_VF
parameter_list|)
value|(0x00091C00 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRSTAT_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRSTAT_VFRD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRSTAT_VFRD_MASK
value|I40E_MASK(0x1, I40E_VPGEN_VFRSTAT_VFRD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRTRIG
parameter_list|(
name|_VF
parameter_list|)
value|(0x00091800 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRTRIG_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRTRIG_VFSWR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPGEN_VFRTRIG_VFSWR_MASK
value|I40E_MASK(0x1, I40E_VPGEN_VFRTRIG_VFSWR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIGEN_RSTAT
parameter_list|(
name|_VSI
parameter_list|)
value|(0x00090800 + ((_VSI) * 4))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VSIGEN_RSTAT_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_VSIGEN_RSTAT_VMRD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VSIGEN_RSTAT_VMRD_MASK
value|I40E_MASK(0x1, I40E_VSIGEN_RSTAT_VMRD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIGEN_RTRIG
parameter_list|(
name|_VSI
parameter_list|)
value|(0x00090000 + ((_VSI) * 4))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VSIGEN_RTRIG_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_VSIGEN_RTRIG_VMSWR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VSIGEN_RTRIG_VMSWR_MASK
value|I40E_MASK(0x1, I40E_VSIGEN_RTRIG_VMSWR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPBASE
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6600 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPBASE_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPBASE_FPMFCOEDDPBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPBASE_FPMFCOEDDPBASE_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLHMC_FCOEDDPBASE_FPMFCOEDDPBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6700 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPCNT_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPCNT_FPMFCOEDDPCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPCNT_FPMFCOEDDPCNT_MASK
value|I40E_MASK(0xFFFFF, I40E_GLHMC_FCOEDDPCNT_FPMFCOEDDPCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPOBJSZ
value|0x000C2010
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPOBJSZ_PMFCOEDDPOBJSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEDDPOBJSZ_PMFCOEDDPOBJSZ_MASK
value|I40E_MASK(0xF, I40E_GLHMC_FCOEDDPOBJSZ_PMFCOEDDPOBJSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFBASE
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6800 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFBASE_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFBASE_FPMFCOEFBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFBASE_FPMFCOEFBASE_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLHMC_FCOEFBASE_FPMFCOEFBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6900 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFCNT_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFCNT_FPMFCOEFCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFCNT_FPMFCOEFCNT_MASK
value|I40E_MASK(0x7FFFFF, I40E_GLHMC_FCOEFCNT_FPMFCOEFCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFMAX
value|0x000C20D0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFMAX_PMFCOEFMAX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFMAX_PMFCOEFMAX_MASK
value|I40E_MASK(0xFFFF, I40E_GLHMC_FCOEFMAX_PMFCOEFMAX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFOBJSZ
value|0x000C2018
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFOBJSZ_PMFCOEFOBJSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEFOBJSZ_PMFCOEFOBJSZ_MASK
value|I40E_MASK(0xF, I40E_GLHMC_FCOEFOBJSZ_PMFCOEFOBJSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEMAX
value|0x000C2014
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEMAX_PMFCOEMAX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FCOEMAX_PMFCOEMAX_MASK
value|I40E_MASK(0x1FFF, I40E_GLHMC_FCOEMAX_PMFCOEMAX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVBASE
parameter_list|(
name|_i
parameter_list|)
value|(0x000C5600 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVBASE_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVBASE_FPMFSIAVBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVBASE_FPMFSIAVBASE_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLHMC_FSIAVBASE_FPMFSIAVBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x000C5700 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVCNT_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVCNT_FPMFSIAVCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVCNT_FPMFSIAVCNT_MASK
value|I40E_MASK(0x1FFFFFFF, I40E_GLHMC_FSIAVCNT_FPMFSIAVCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVCNT_RSVD_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVCNT_RSVD_MASK
value|I40E_MASK(0x7, I40E_GLHMC_FSIAVCNT_RSVD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVMAX
value|0x000C2068
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVMAX_PMFSIAVMAX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVMAX_PMFSIAVMAX_MASK
value|I40E_MASK(0x1FFFF, I40E_GLHMC_FSIAVMAX_PMFSIAVMAX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVOBJSZ
value|0x000C2064
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVOBJSZ_PMFSIAVOBJSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIAVOBJSZ_PMFSIAVOBJSZ_MASK
value|I40E_MASK(0xF, I40E_GLHMC_FSIAVOBJSZ_PMFSIAVOBJSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCBASE
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6000 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCBASE_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCBASE_FPMFSIMCBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCBASE_FPMFSIMCBASE_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLHMC_FSIMCBASE_FPMFSIMCBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6100 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCCNT_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCCNT_FPMFSIMCSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCCNT_FPMFSIMCSZ_MASK
value|I40E_MASK(0x1FFFFFFF, I40E_GLHMC_FSIMCCNT_FPMFSIMCSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCMAX
value|0x000C2060
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCMAX_PMFSIMCMAX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCMAX_PMFSIMCMAX_MASK
value|I40E_MASK(0x3FFF, I40E_GLHMC_FSIMCMAX_PMFSIMCMAX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCOBJSZ
value|0x000C205c
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCOBJSZ_PMFSIMCOBJSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_FSIMCOBJSZ_PMFSIMCOBJSZ_MASK
value|I40E_MASK(0xF, I40E_GLHMC_FSIMCOBJSZ_PMFSIMCOBJSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANQMAX
value|0x000C2008
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_LANQMAX_PMLANQMAX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANQMAX_PMLANQMAX_MASK
value|I40E_MASK(0x7FF, I40E_GLHMC_LANQMAX_PMLANQMAX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXBASE
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6400 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXBASE_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXBASE_FPMLANRXBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXBASE_FPMLANRXBASE_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLHMC_LANRXBASE_FPMLANRXBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6500 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXCNT_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXCNT_FPMLANRXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXCNT_FPMLANRXCNT_MASK
value|I40E_MASK(0x7FF, I40E_GLHMC_LANRXCNT_FPMLANRXCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXOBJSZ
value|0x000C200c
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXOBJSZ_PMLANRXOBJSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANRXOBJSZ_PMLANRXOBJSZ_MASK
value|I40E_MASK(0xF, I40E_GLHMC_LANRXOBJSZ_PMLANRXOBJSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXBASE
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6200 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXBASE_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXBASE_FPMLANTXBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXBASE_FPMLANTXBASE_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLHMC_LANTXBASE_FPMLANTXBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXBASE_RSVD_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXBASE_RSVD_MASK
value|I40E_MASK(0xFF, I40E_GLHMC_LANTXBASE_RSVD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x000C6300 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXCNT_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXCNT_FPMLANTXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXCNT_FPMLANTXCNT_MASK
value|I40E_MASK(0x7FF, I40E_GLHMC_LANTXCNT_FPMLANTXCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXOBJSZ
value|0x000C2004
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXOBJSZ_PMLANTXOBJSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_LANTXOBJSZ_PMLANTXOBJSZ_MASK
value|I40E_MASK(0xF, I40E_GLHMC_LANTXOBJSZ_PMLANTXOBJSZ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_PFASSIGN
parameter_list|(
name|_i
parameter_list|)
value|(0x000C0c00 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_PFASSIGN_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_PFASSIGN_PMFCNPFASSIGN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_PFASSIGN_PMFCNPFASSIGN_MASK
value|I40E_MASK(0xF, I40E_GLHMC_PFASSIGN_PMFCNPFASSIGN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_SDPART
parameter_list|(
name|_i
parameter_list|)
value|(0x000C0800 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLHMC_SDPART_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_SDPART_PMSDBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_SDPART_PMSDBASE_MASK
value|I40E_MASK(0xFFF, I40E_GLHMC_SDPART_PMSDBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_SDPART_PMSDSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLHMC_SDPART_PMSDSIZE_MASK
value|I40E_MASK(0x1FFF, I40E_GLHMC_SDPART_PMSDSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORDATA
value|0x000C0500
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORDATA_HMC_ERROR_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORDATA_HMC_ERROR_DATA_MASK
value|I40E_MASK(0x3FFFFFFF, I40E_PFHMC_ERRORDATA_HMC_ERROR_DATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO
value|0x000C0400
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_PMF_INDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_PMF_INDEX_MASK
value|I40E_MASK(0x1F, I40E_PFHMC_ERRORINFO_PMF_INDEX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_PMF_ISVF_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_PMF_ISVF_MASK
value|I40E_MASK(0x1, I40E_PFHMC_ERRORINFO_PMF_ISVF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_HMC_ERROR_TYPE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_HMC_ERROR_TYPE_MASK
value|I40E_MASK(0xF, I40E_PFHMC_ERRORINFO_HMC_ERROR_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_HMC_OBJECT_TYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_HMC_OBJECT_TYPE_MASK
value|I40E_MASK(0x1F, I40E_PFHMC_ERRORINFO_HMC_OBJECT_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_ERROR_DETECTED_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_ERRORINFO_ERROR_DETECTED_MASK
value|I40E_MASK(0x1, I40E_PFHMC_ERRORINFO_ERROR_DETECTED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_PDINV
value|0x000C0300
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFHMC_PDINV_PMSDIDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_PDINV_PMSDIDX_MASK
value|I40E_MASK(0xFFF, I40E_PFHMC_PDINV_PMSDIDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_PDINV_PMPDIDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_PDINV_PMPDIDX_MASK
value|I40E_MASK(0x1FF, I40E_PFHMC_PDINV_PMPDIDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDCMD
value|0x000C0000
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFHMC_SDCMD_PMSDIDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDCMD_PMSDIDX_MASK
value|I40E_MASK(0xFFF, I40E_PFHMC_SDCMD_PMSDIDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDCMD_PMSDWR_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDCMD_PMSDWR_MASK
value|I40E_MASK(0x1, I40E_PFHMC_SDCMD_PMSDWR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATAHIGH
value|0x000C0200
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATAHIGH_PMSDDATAHIGH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATAHIGH_PMSDDATAHIGH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PFHMC_SDDATAHIGH_PMSDDATAHIGH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW
value|0x000C0100
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDVALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDVALID_MASK
value|I40E_MASK(0x1, I40E_PFHMC_SDDATALOW_PMSDVALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDTYPE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDTYPE_MASK
value|I40E_MASK(0x1, I40E_PFHMC_SDDATALOW_PMSDTYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDBPCOUNT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDBPCOUNT_MASK
value|I40E_MASK(0x3FF, I40E_PFHMC_SDDATALOW_PMSDBPCOUNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDDATALOW_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PFHMC_SDDATALOW_PMSDDATALOW_MASK
value|I40E_MASK(0xFFFFF, I40E_PFHMC_SDDATALOW_PMSDDATALOW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_GP_FUSE
parameter_list|(
name|_i
parameter_list|)
value|(0x0009400C + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...28 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_GP_FUSE_MAX_INDEX
value|28
end_define

begin_define
define|#
directive|define
name|I40E_GL_GP_FUSE_GL_GP_FUSE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_GP_FUSE_GL_GP_FUSE_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_GP_FUSE_GL_GP_FUSE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE
value|0x00094008
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_FOUR_PORT_ENABLE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_FOUR_PORT_ENABLE_MASK
value|I40E_MASK(0x1, I40E_GL_UFUSE_FOUR_PORT_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_NIC_ID_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_NIC_ID_MASK
value|I40E_MASK(0x1, I40E_GL_UFUSE_NIC_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_ULT_LOCKOUT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_ULT_LOCKOUT_MASK
value|I40E_MASK(0x1, I40E_GL_UFUSE_ULT_LOCKOUT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_CLS_LOCKOUT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GL_UFUSE_CLS_LOCKOUT_MASK
value|I40E_MASK(0x1, I40E_GL_UFUSE_CLS_LOCKOUT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA
value|0x00088188
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO0_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO0_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO0_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO1_ENA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO1_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO1_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO2_ENA_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO2_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO2_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO3_ENA_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO3_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO3_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO4_ENA_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO4_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO4_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO5_ENA_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO5_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO5_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO6_ENA_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO6_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO6_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO7_ENA_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO7_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO7_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO8_ENA_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO8_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO8_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO9_ENA_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO9_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO9_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO10_ENA_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO10_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO10_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO11_ENA_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO11_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO11_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO12_ENA_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO12_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO12_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO13_ENA_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO13_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO13_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO14_ENA_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO14_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO14_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO15_ENA_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO15_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO15_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO16_ENA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO16_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO16_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO17_ENA_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO17_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO17_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO18_ENA_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO18_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO18_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO19_ENA_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO19_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO19_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO20_ENA_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO20_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO20_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO21_ENA_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO21_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO21_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO22_ENA_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO22_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO22_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO23_ENA_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO23_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO23_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO24_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO24_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO24_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO25_ENA_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO25_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO25_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO26_ENA_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO26_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO26_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO27_ENA_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO27_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO27_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO28_ENA_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO28_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO28_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO29_ENA_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_EMPINT_GPIO_ENA_GPIO29_ENA_MASK
value|I40E_MASK(0x1, I40E_EMPINT_GPIO_ENA_GPIO29_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTMDIO_NUM
value|0x0003F100
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTMDIO_NUM_PORT_NUM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTMDIO_NUM_PORT_NUM_MASK
value|I40E_MASK(0x3, I40E_PFGEN_PORTMDIO_NUM_PORT_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTMDIO_NUM_VFLINK_STAT_ENA_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PFGEN_PORTMDIO_NUM_VFLINK_STAT_ENA_MASK
value|I40E_MASK(0x1, I40E_PFGEN_PORTMDIO_NUM_VFLINK_STAT_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL
value|0x00038700
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_MSIX_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_MSIX_INDX_MASK
value|I40E_MASK(0xFF, I40E_PFINT_AEQCTL_MSIX_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_ITR_INDX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_PFINT_AEQCTL_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_MSIX0_INDX_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_MSIX0_INDX_MASK
value|I40E_MASK(0x7, I40E_PFINT_AEQCTL_MSIX0_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_CAUSE_ENA_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_CAUSE_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_AEQCTL_CAUSE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_INTEVENT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_AEQCTL_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_PFINT_AEQCTL_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL
parameter_list|(
name|_INTPF
parameter_list|)
value|(0x00036800 + ((_INTPF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_MSIX_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_MSIX_INDX_MASK
value|I40E_MASK(0xFF, I40E_PFINT_CEQCTL_MSIX_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_ITR_INDX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_PFINT_CEQCTL_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_MSIX0_INDX_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_MSIX0_INDX_MASK
value|I40E_MASK(0x7, I40E_PFINT_CEQCTL_MSIX0_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_NEXTQ_INDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_NEXTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_PFINT_CEQCTL_NEXTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_NEXTQ_TYPE_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_NEXTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_PFINT_CEQCTL_NEXTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_CAUSE_ENA_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_CAUSE_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_CEQCTL_CAUSE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_INTEVENT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_CEQCTL_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_PFINT_CEQCTL_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0
value|0x00038480
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_INTENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_INTENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTL0_INTENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_CLEARPBA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_CLEARPBA_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTL0_CLEARPBA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_SWINT_TRIG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_SWINT_TRIG_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTL0_SWINT_TRIG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_ITR_INDX_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_PFINT_DYN_CTL0_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_INTERVAL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_PFINT_DYN_CTL0_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_SW_ITR_INDX_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_SW_ITR_INDX_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTL0_SW_ITR_INDX_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_SW_ITR_INDX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_SW_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_PFINT_DYN_CTL0_SW_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_INTENA_MSK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTL0_INTENA_MSK_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTL0_INTENA_MSK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN
parameter_list|(
name|_INTPF
parameter_list|)
value|(0x00034800 + ((_INTPF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_INTENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_INTENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTLN_INTENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_CLEARPBA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_CLEARPBA_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTLN_CLEARPBA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_SWINT_TRIG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_SWINT_TRIG_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTLN_SWINT_TRIG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_ITR_INDX_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_PFINT_DYN_CTLN_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_INTERVAL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_PFINT_DYN_CTLN_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_SW_ITR_INDX_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_SW_ITR_INDX_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTLN_SW_ITR_INDX_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_SW_ITR_INDX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_SW_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_PFINT_DYN_CTLN_SW_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_INTENA_MSK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_DYN_CTLN_INTENA_MSK_MASK
value|I40E_MASK(0x1, I40E_PFINT_DYN_CTLN_INTENA_MSK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA
value|0x00088080
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO0_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO0_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO0_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO1_ENA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO1_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO1_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO2_ENA_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO2_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO2_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO3_ENA_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO3_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO3_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO4_ENA_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO4_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO4_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO5_ENA_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO5_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO5_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO6_ENA_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO6_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO6_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO7_ENA_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO7_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO7_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO8_ENA_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO8_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO8_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO9_ENA_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO9_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO9_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO10_ENA_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO10_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO10_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO11_ENA_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO11_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO11_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO12_ENA_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO12_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO12_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO13_ENA_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO13_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO13_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO14_ENA_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO14_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO14_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO15_ENA_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO15_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO15_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO16_ENA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO16_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO16_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO17_ENA_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO17_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO17_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO18_ENA_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO18_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO18_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO19_ENA_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO19_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO19_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO20_ENA_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO20_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO20_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO21_ENA_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO21_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO21_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO22_ENA_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO22_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO22_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO23_ENA_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO23_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO23_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO24_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO24_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO24_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO25_ENA_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO25_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO25_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO26_ENA_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO26_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO26_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO27_ENA_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO27_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO27_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO28_ENA_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO28_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO28_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO29_ENA_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_GPIO_ENA_GPIO29_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_GPIO_ENA_GPIO29_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0
value|0x00038780
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_INTEVENT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_0_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_0_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_1_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_1_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_2_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_2_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_3_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_3_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_4_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_4_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_5_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_5_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_6_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_6_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_7_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_QUEUE_7_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_QUEUE_7_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ECC_ERR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ECC_ERR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ECC_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_MAL_DETECT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_MAL_DETECT_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_MAL_DETECT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_GRST_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_GRST_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_GRST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_PCI_EXCEPTION_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_PCI_EXCEPTION_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_PCI_EXCEPTION_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_GPIO_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_GPIO_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_GPIO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_TIMESYNC_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_TIMESYNC_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_TIMESYNC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_STORM_DETECT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_STORM_DETECT_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_STORM_DETECT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_LINK_STAT_CHANGE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_LINK_STAT_CHANGE_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_LINK_STAT_CHANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_HMC_ERR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_HMC_ERR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_HMC_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_PE_CRITERR_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_PE_CRITERR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_PE_CRITERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_VFLR_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_VFLR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_VFLR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ADMINQ_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ADMINQ_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ADMINQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_SWINT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_SWINT_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_SWINT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA
value|0x00038800
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_ECC_ERR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_ECC_ERR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_ECC_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_MAL_DETECT_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_MAL_DETECT_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_MAL_DETECT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_GRST_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_GRST_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_GRST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_PCI_EXCEPTION_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_PCI_EXCEPTION_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_PCI_EXCEPTION_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_GPIO_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_GPIO_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_GPIO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_TIMESYNC_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_TIMESYNC_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_TIMESYNC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_STORM_DETECT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_STORM_DETECT_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_STORM_DETECT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_LINK_STAT_CHANGE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_LINK_STAT_CHANGE_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_LINK_STAT_CHANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_HMC_ERR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_HMC_ERR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_HMC_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_PE_CRITERR_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_PE_CRITERR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_PE_CRITERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_VFLR_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_VFLR_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_VFLR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_ADMINQ_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_ADMINQ_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_ADMINQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_RSVD_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ICR0_ENA_RSVD_MASK
value|I40E_MASK(0x1, I40E_PFINT_ICR0_ENA_RSVD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ITR0
parameter_list|(
name|_i
parameter_list|)
value|(0x00038000 + ((_i) * 128))
end_define

begin_comment
comment|/* _i=0...2 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_ITR0_MAX_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ITR0_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ITR0_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_PFINT_ITR0_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ITRN
parameter_list|(
name|_i
parameter_list|,
name|_INTPF
parameter_list|)
value|(0x00030000 + ((_i) * 2048 + (_INTPF) * 4))
end_define

begin_comment
comment|/* _i=0...2, _INTPF=0...511 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_ITRN_MAX_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ITRN_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_ITRN_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_PFINT_ITRN_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLST0
value|0x00038500
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLST0_FIRSTQ_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLST0_FIRSTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_PFINT_LNKLST0_FIRSTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLST0_FIRSTQ_TYPE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLST0_FIRSTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_PFINT_LNKLST0_FIRSTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLSTN
parameter_list|(
name|_INTPF
parameter_list|)
value|(0x00035000 + ((_INTPF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLSTN_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLSTN_FIRSTQ_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLSTN_FIRSTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_PFINT_LNKLSTN_FIRSTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLSTN_FIRSTQ_TYPE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_LNKLSTN_FIRSTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_PFINT_LNKLSTN_FIRSTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATE0
value|0x00038580
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_RATE0_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATE0_INTERVAL_MASK
value|I40E_MASK(0x3F, I40E_PFINT_RATE0_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATE0_INTRL_ENA_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATE0_INTRL_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_RATE0_INTRL_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATEN
parameter_list|(
name|_INTPF
parameter_list|)
value|(0x00035800 + ((_INTPF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_RATEN_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATEN_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATEN_INTERVAL_MASK
value|I40E_MASK(0x3F, I40E_PFINT_RATEN_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATEN_INTRL_ENA_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_RATEN_INTRL_ENA_MASK
value|I40E_MASK(0x1, I40E_PFINT_RATEN_INTRL_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_STAT_CTL0
value|0x00038400
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFINT_STAT_CTL0_OTHER_ITR_INDX_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFINT_STAT_CTL0_OTHER_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_PFINT_STAT_CTL0_OTHER_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL
parameter_list|(
name|_Q
parameter_list|)
value|(0x0003A000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_MSIX_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_MSIX_INDX_MASK
value|I40E_MASK(0xFF, I40E_QINT_RQCTL_MSIX_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_ITR_INDX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_QINT_RQCTL_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_MSIX0_INDX_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_MSIX0_INDX_MASK
value|I40E_MASK(0x7, I40E_QINT_RQCTL_MSIX0_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_NEXTQ_INDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_NEXTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_QINT_RQCTL_NEXTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_NEXTQ_TYPE_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_NEXTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_QINT_RQCTL_NEXTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_CAUSE_ENA_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_CAUSE_ENA_MASK
value|I40E_MASK(0x1, I40E_QINT_RQCTL_CAUSE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_INTEVENT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_QINT_RQCTL_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_QINT_RQCTL_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL
parameter_list|(
name|_Q
parameter_list|)
value|(0x0003C000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_MSIX_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_MSIX_INDX_MASK
value|I40E_MASK(0xFF, I40E_QINT_TQCTL_MSIX_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_ITR_INDX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_QINT_TQCTL_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_MSIX0_INDX_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_MSIX0_INDX_MASK
value|I40E_MASK(0x7, I40E_QINT_TQCTL_MSIX0_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_NEXTQ_INDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_NEXTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_QINT_TQCTL_NEXTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_NEXTQ_TYPE_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_NEXTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_QINT_TQCTL_NEXTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_CAUSE_ENA_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_CAUSE_ENA_MASK
value|I40E_MASK(0x1, I40E_QINT_TQCTL_CAUSE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_INTEVENT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_QINT_TQCTL_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_QINT_TQCTL_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0
parameter_list|(
name|_VF
parameter_list|)
value|(0x0002A400 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_INTENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_INTENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL0_INTENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_CLEARPBA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_CLEARPBA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL0_CLEARPBA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_SWINT_TRIG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_SWINT_TRIG_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL0_SWINT_TRIG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_ITR_INDX_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTL0_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_INTERVAL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_DYN_CTL0_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_SW_ITR_INDX_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_SW_ITR_INDX_ENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL0_SW_ITR_INDX_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_SW_ITR_INDX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_SW_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTL0_SW_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_INTENA_MSK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL0_INTENA_MSK_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL0_INTENA_MSK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN
parameter_list|(
name|_INTVF
parameter_list|)
value|(0x00024800 + ((_INTVF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_INTENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_INTENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN_INTENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_CLEARPBA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_CLEARPBA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN_CLEARPBA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_SWINT_TRIG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_SWINT_TRIG_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN_SWINT_TRIG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_ITR_INDX_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTLN_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_INTERVAL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_DYN_CTLN_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_SW_ITR_INDX_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_SW_ITR_INDX_ENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN_SW_ITR_INDX_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_SW_ITR_INDX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_SW_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTLN_SW_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_INTENA_MSK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN_INTENA_MSK_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN_INTENA_MSK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0
parameter_list|(
name|_VF
parameter_list|)
value|(0x0002BC00 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_INTEVENT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_0_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_0_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_QUEUE_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_1_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_1_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_QUEUE_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_2_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_2_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_QUEUE_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_3_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_QUEUE_3_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_QUEUE_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_LINK_STAT_CHANGE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_LINK_STAT_CHANGE_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_LINK_STAT_CHANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ADMINQ_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ADMINQ_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_ADMINQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_SWINT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_SWINT_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_SWINT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA
parameter_list|(
name|_VF
parameter_list|)
value|(0x0002C000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA_LINK_STAT_CHANGE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA_LINK_STAT_CHANGE_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_ENA_LINK_STAT_CHANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA_ADMINQ_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA_ADMINQ_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_ENA_ADMINQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA_RSVD_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA_RSVD_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_ENA_RSVD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITR0
parameter_list|(
name|_i
parameter_list|,
name|_VF
parameter_list|)
value|(0x00028000 + ((_i) * 1024 + (_VF) * 4))
end_define

begin_comment
comment|/* _i=0...2, _VF=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ITR0_MAX_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITR0_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITR0_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_ITR0_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN
parameter_list|(
name|_i
parameter_list|,
name|_INTVF
parameter_list|)
value|(0x00020000 + ((_i) * 2048 + (_INTVF) * 4))
end_define

begin_comment
comment|/* _i=0...2, _INTVF=0...511 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN_MAX_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_ITRN_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_STAT_CTL0
parameter_list|(
name|_VF
parameter_list|)
value|(0x0002A000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_STAT_CTL0_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_STAT_CTL0_OTHER_ITR_INDX_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_STAT_CTL0_OTHER_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_STAT_CTL0_OTHER_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL
parameter_list|(
name|_VF
parameter_list|)
value|(0x0002B800 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_MSIX_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_MSIX_INDX_MASK
value|I40E_MASK(0xFF, I40E_VPINT_AEQCTL_MSIX_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_ITR_INDX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VPINT_AEQCTL_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_MSIX0_INDX_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_MSIX0_INDX_MASK
value|I40E_MASK(0x7, I40E_VPINT_AEQCTL_MSIX0_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_CAUSE_ENA_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_CAUSE_ENA_MASK
value|I40E_MASK(0x1, I40E_VPINT_AEQCTL_CAUSE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_INTEVENT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_AEQCTL_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_VPINT_AEQCTL_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL
parameter_list|(
name|_INTVF
parameter_list|)
value|(0x00026800 + ((_INTVF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_MSIX_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_MSIX_INDX_MASK
value|I40E_MASK(0xFF, I40E_VPINT_CEQCTL_MSIX_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_ITR_INDX_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VPINT_CEQCTL_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_MSIX0_INDX_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_MSIX0_INDX_MASK
value|I40E_MASK(0x7, I40E_VPINT_CEQCTL_MSIX0_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_NEXTQ_INDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_NEXTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_VPINT_CEQCTL_NEXTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_NEXTQ_TYPE_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_NEXTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_VPINT_CEQCTL_NEXTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_CAUSE_ENA_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_CAUSE_ENA_MASK
value|I40E_MASK(0x1, I40E_VPINT_CEQCTL_CAUSE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_INTEVENT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_CEQCTL_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_VPINT_CEQCTL_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLST0
parameter_list|(
name|_VF
parameter_list|)
value|(0x0002A800 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLST0_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLST0_FIRSTQ_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLST0_FIRSTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_VPINT_LNKLST0_FIRSTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLST0_FIRSTQ_TYPE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLST0_FIRSTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_VPINT_LNKLST0_FIRSTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLSTN
parameter_list|(
name|_INTVF
parameter_list|)
value|(0x00025000 + ((_INTVF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLSTN_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLSTN_FIRSTQ_INDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLSTN_FIRSTQ_INDX_MASK
value|I40E_MASK(0x7FF, I40E_VPINT_LNKLSTN_FIRSTQ_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLSTN_FIRSTQ_TYPE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_LNKLSTN_FIRSTQ_TYPE_MASK
value|I40E_MASK(0x3, I40E_VPINT_LNKLSTN_FIRSTQ_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATE0
parameter_list|(
name|_VF
parameter_list|)
value|(0x0002AC00 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VPINT_RATE0_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATE0_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATE0_INTERVAL_MASK
value|I40E_MASK(0x3F, I40E_VPINT_RATE0_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATE0_INTRL_ENA_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATE0_INTRL_ENA_MASK
value|I40E_MASK(0x1, I40E_VPINT_RATE0_INTRL_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATEN
parameter_list|(
name|_INTVF
parameter_list|)
value|(0x00025800 + ((_INTVF) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VPINT_RATEN_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATEN_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATEN_INTERVAL_MASK
value|I40E_MASK(0x3F, I40E_VPINT_RATEN_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATEN_INTRL_ENA_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_VPINT_RATEN_INTRL_ENA_MASK
value|I40E_MASK(0x1, I40E_VPINT_RATEN_INTRL_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_RDPU_CNTRL
value|0x00051060
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_RDPU_CNTRL_RX_PAD_EN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_RDPU_CNTRL_RX_PAD_EN_MASK
value|I40E_MASK(0x1, I40E_GL_RDPU_CNTRL_RX_PAD_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_RDPU_CNTRL_ECO_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GL_RDPU_CNTRL_ECO_MASK
value|I40E_MASK(0x7FFFFFFF, I40E_GL_RDPU_CNTRL_ECO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_RCTL_0
value|0x0012A500
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLLAN_RCTL_0_PXE_MODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_RCTL_0_PXE_MODE_MASK
value|I40E_MASK(0x1, I40E_GLLAN_RCTL_0_PXE_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_F
value|0x000442D8
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_F_TCPMSKF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_F_TCPMSKF_MASK
value|I40E_MASK(0xFFF, I40E_GLLAN_TSOMSK_F_TCPMSKF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_L
value|0x000442E0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_L_TCPMSKL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_L_TCPMSKL_MASK
value|I40E_MASK(0xFFF, I40E_GLLAN_TSOMSK_L_TCPMSKL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_M
value|0x000442DC
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_M_TCPMSKM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TSOMSK_M_TCPMSKM_MASK
value|I40E_MASK(0xFFF, I40E_GLLAN_TSOMSK_M_TCPMSKM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS
parameter_list|(
name|_i
parameter_list|)
value|(0x000e6500 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...11 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_MAX_INDEX
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_QINDX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_QINDX_MASK
value|I40E_MASK(0x7FF, I40E_GLLAN_TXPRE_QDIS_QINDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_QDIS_STAT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_QDIS_STAT_MASK
value|I40E_MASK(0x1, I40E_GLLAN_TXPRE_QDIS_QDIS_STAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_SET_QDIS_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_SET_QDIS_MASK
value|I40E_MASK(0x1, I40E_GLLAN_TXPRE_QDIS_SET_QDIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_CLEAR_QDIS_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLLAN_TXPRE_QDIS_CLEAR_QDIS_MASK
value|I40E_MASK(0x1, I40E_GLLAN_TXPRE_QDIS_CLEAR_QDIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFLAN_QALLOC
value|0x001C0400
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFLAN_QALLOC_FIRSTQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFLAN_QALLOC_FIRSTQ_MASK
value|I40E_MASK(0x7FF, I40E_PFLAN_QALLOC_FIRSTQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFLAN_QALLOC_LASTQ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFLAN_QALLOC_LASTQ_MASK
value|I40E_MASK(0x7FF, I40E_PFLAN_QALLOC_LASTQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFLAN_QALLOC_VALID_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFLAN_QALLOC_VALID_MASK
value|I40E_MASK(0x1, I40E_PFLAN_QALLOC_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QRX_ENA
parameter_list|(
name|_Q
parameter_list|)
value|(0x00120000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_QRX_ENA_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QRX_ENA_QENA_REQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QRX_ENA_QENA_REQ_MASK
value|I40E_MASK(0x1, I40E_QRX_ENA_QENA_REQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QRX_ENA_FAST_QDIS_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_QRX_ENA_FAST_QDIS_MASK
value|I40E_MASK(0x1, I40E_QRX_ENA_FAST_QDIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QRX_ENA_QENA_STAT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_QRX_ENA_QENA_STAT_MASK
value|I40E_MASK(0x1, I40E_QRX_ENA_QENA_STAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QRX_TAIL
parameter_list|(
name|_Q
parameter_list|)
value|(0x00128000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_QRX_TAIL_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QRX_TAIL_TAIL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QRX_TAIL_TAIL_MASK
value|I40E_MASK(0x1FFF, I40E_QRX_TAIL_TAIL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL
parameter_list|(
name|_Q
parameter_list|)
value|(0x00104000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_QTX_CTL_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_PFVF_Q_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_PFVF_Q_MASK
value|I40E_MASK(0x3, I40E_QTX_CTL_PFVF_Q_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_PF_INDX_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_PF_INDX_MASK
value|I40E_MASK(0xF, I40E_QTX_CTL_PF_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_VFVM_INDX_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_QTX_CTL_VFVM_INDX_MASK
value|I40E_MASK(0x1FF, I40E_QTX_CTL_VFVM_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_ENA
parameter_list|(
name|_Q
parameter_list|)
value|(0x00100000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_QTX_ENA_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QTX_ENA_QENA_REQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QTX_ENA_QENA_REQ_MASK
value|I40E_MASK(0x1, I40E_QTX_ENA_QENA_REQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_ENA_FAST_QDIS_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_QTX_ENA_FAST_QDIS_MASK
value|I40E_MASK(0x1, I40E_QTX_ENA_FAST_QDIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_ENA_QENA_STAT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_QTX_ENA_QENA_STAT_MASK
value|I40E_MASK(0x1, I40E_QTX_ENA_QENA_STAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_HEAD
parameter_list|(
name|_Q
parameter_list|)
value|(0x000E4000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_QTX_HEAD_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QTX_HEAD_HEAD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QTX_HEAD_HEAD_MASK
value|I40E_MASK(0x1FFF, I40E_QTX_HEAD_HEAD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_HEAD_RS_PENDING_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_QTX_HEAD_RS_PENDING_MASK
value|I40E_MASK(0x1, I40E_QTX_HEAD_RS_PENDING_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_TAIL
parameter_list|(
name|_Q
parameter_list|)
value|(0x00108000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...1535 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_QTX_TAIL_MAX_INDEX
value|1535
end_define

begin_define
define|#
directive|define
name|I40E_QTX_TAIL_TAIL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QTX_TAIL_TAIL_MASK
value|I40E_MASK(0x1FFF, I40E_QTX_TAIL_TAIL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPLAN_MAPENA
parameter_list|(
name|_VF
parameter_list|)
value|(0x00074000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VPLAN_MAPENA_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VPLAN_MAPENA_TXRX_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPLAN_MAPENA_TXRX_ENA_MASK
value|I40E_MASK(0x1, I40E_VPLAN_MAPENA_TXRX_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPLAN_QTABLE
parameter_list|(
name|_i
parameter_list|,
name|_VF
parameter_list|)
value|(0x00070000 + ((_i) * 1024 + (_VF) * 4))
end_define

begin_comment
comment|/* _i=0...15, _VF=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VPLAN_QTABLE_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_VPLAN_QTABLE_QINDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPLAN_QTABLE_QINDEX_MASK
value|I40E_MASK(0x7FF, I40E_VPLAN_QTABLE_QINDEX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QBASE
parameter_list|(
name|_VSI
parameter_list|)
value|(0x0020C800 + ((_VSI) * 4))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VSILAN_QBASE_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QBASE_VSIBASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QBASE_VSIBASE_MASK
value|I40E_MASK(0x7FF, I40E_VSILAN_QBASE_VSIBASE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QBASE_VSIQTABLE_ENA_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QBASE_VSIQTABLE_ENA_MASK
value|I40E_MASK(0x1, I40E_VSILAN_QBASE_VSIQTABLE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QTABLE
parameter_list|(
name|_i
parameter_list|,
name|_VSI
parameter_list|)
value|(0x00200000 + ((_i) * 2048 + (_VSI) * 4))
end_define

begin_comment
comment|/* _i=0...7, _VSI=0...383 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VSILAN_QTABLE_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QTABLE_QINDEX_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QTABLE_QINDEX_0_MASK
value|I40E_MASK(0x7FF, I40E_VSILAN_QTABLE_QINDEX_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QTABLE_QINDEX_1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VSILAN_QTABLE_QINDEX_1_MASK
value|I40E_MASK(0x7FF, I40E_VSILAN_QTABLE_QINDEX_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGL_SAH
value|0x001E2140
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTGL_SAH_FC_SAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTGL_SAH_FC_SAH_MASK
value|I40E_MASK(0xFFFF, I40E_PRTGL_SAH_FC_SAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGL_SAH_MFS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTGL_SAH_MFS_MASK
value|I40E_MASK(0xFFFF, I40E_PRTGL_SAH_MFS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTGL_SAL
value|0x001E2120
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTGL_SAL_FC_SAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTGL_SAL_FC_SAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTGL_SAL_FC_SAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GCP
value|0x001E30E0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GCP_HSEC_CTL_RX_ENABLE_GCP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GCP_HSEC_CTL_RX_ENABLE_GCP_MASK
value|I40E_MASK(0x1, I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GCP_HSEC_CTL_RX_ENABLE_GCP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GPP
value|0x001E3260
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GPP_HSEC_CTL_RX_ENABLE_GPP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GPP_HSEC_CTL_RX_ENABLE_GPP_MASK
value|I40E_MASK(0x1, I40E_PRTMAC_HSEC_CTL_RX_ENABLE_GPP_HSEC_CTL_RX_ENABLE_GPP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_PPP
value|0x001E32E0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_PPP_HSEC_CTL_RX_ENABLE_PPP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_ENABLE_PPP_HSEC_CTL_RX_ENABLE_PPP_MASK
value|I40E_MASK(0x1, I40E_PRTMAC_HSEC_CTL_RX_ENABLE_PPP_HSEC_CTL_RX_ENABLE_PPP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_FORWARD_CONTROL
value|0x001E3360
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_FORWARD_CONTROL_HSEC_CTL_RX_FORWARD_CONTROL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_FORWARD_CONTROL_HSEC_CTL_RX_FORWARD_CONTROL_MASK
value|I40E_MASK(0x1, I40E_PRTMAC_HSEC_CTL_RX_FORWARD_CONTROL_HSEC_CTL_RX_FORWARD_CONTROL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART1
value|0x001E3110
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART1_HSEC_CTL_RX_PAUSE_DA_UCAST_PART1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART1_HSEC_CTL_RX_PAUSE_DA_UCAST_PART1_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART1_HSEC_CTL_RX_PAUSE_DA_UCAST_PART1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART2
value|0x001E3120
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART2_HSEC_CTL_RX_PAUSE_DA_UCAST_PART2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART2_HSEC_CTL_RX_PAUSE_DA_UCAST_PART2_MASK
value|I40E_MASK(0xFFFF, I40E_PRTMAC_HSEC_CTL_RX_PAUSE_DA_UCAST_PART2_HSEC_CTL_RX_PAUSE_DA_UCAST_PART2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_ENABLE
value|0x001E30C0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_ENABLE_HSEC_CTL_RX_PAUSE_ENABLE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_ENABLE_HSEC_CTL_RX_PAUSE_ENABLE_MASK
value|I40E_MASK(0x1FF, I40E_PRTMAC_HSEC_CTL_RX_PAUSE_ENABLE_HSEC_CTL_RX_PAUSE_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART1
value|0x001E3140
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART1_HSEC_CTL_RX_PAUSE_SA_PART1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART1_HSEC_CTL_RX_PAUSE_SA_PART1_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART1_HSEC_CTL_RX_PAUSE_SA_PART1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART2
value|0x001E3150
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART2_HSEC_CTL_RX_PAUSE_SA_PART2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART2_HSEC_CTL_RX_PAUSE_SA_PART2_MASK
value|I40E_MASK(0xFFFF, I40E_PRTMAC_HSEC_CTL_RX_PAUSE_SA_PART2_HSEC_CTL_RX_PAUSE_SA_PART2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_ENABLE
value|0x001E30D0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_ENABLE_HSEC_CTL_TX_PAUSE_ENABLE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_ENABLE_HSEC_CTL_TX_PAUSE_ENABLE_MASK
value|I40E_MASK(0x1FF, I40E_PRTMAC_HSEC_CTL_TX_PAUSE_ENABLE_HSEC_CTL_TX_PAUSE_ENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_QUANTA
parameter_list|(
name|_i
parameter_list|)
value|(0x001E3370 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...8 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_QUANTA_MAX_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_QUANTA_HSEC_CTL_TX_PAUSE_QUANTA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_QUANTA_HSEC_CTL_TX_PAUSE_QUANTA_MASK
value|I40E_MASK(0xFFFF, I40E_PRTMAC_HSEC_CTL_TX_PAUSE_QUANTA_HSEC_CTL_TX_PAUSE_QUANTA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_REFRESH_TIMER
parameter_list|(
name|_i
parameter_list|)
value|(0x001E3400 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...8 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_REFRESH_TIMER_MAX_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_REFRESH_TIMER_HSEC_CTL_TX_PAUSE_REFRESH_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_PAUSE_REFRESH_TIMER_HSEC_CTL_TX_PAUSE_REFRESH_TIMER_MASK
value|I40E_MASK(0xFFFF, I40E_PRTMAC_HSEC_CTL_TX_PAUSE_REFRESH_TIMER_HSEC_CTL_TX_PAUSE_REFRESH_TIMER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_SA_PART1
value|0x001E34B0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_SA_PART1_HSEC_CTL_TX_SA_PART1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_SA_PART1_HSEC_CTL_TX_SA_PART1_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTMAC_HSEC_CTL_TX_SA_PART1_HSEC_CTL_TX_SA_PART1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_SA_PART2
value|0x001E34C0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_SA_PART2_HSEC_CTL_TX_SA_PART2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_HSEC_CTL_TX_SA_PART2_HSEC_CTL_TX_SA_PART2_MASK
value|I40E_MASK(0xFFFF, I40E_PRTMAC_HSEC_CTL_TX_SA_PART2_HSEC_CTL_TX_SA_PART2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A
value|0x0008C480
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE3_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE2_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE2_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE1_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE0_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE0_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_TX_LANE0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE3_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE3_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE2_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE2_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE1_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE0_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE0_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_A_SWAP_RX_LANE0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B
value|0x0008C484
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE3_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE3_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE2_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE2_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE1_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE0_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE0_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_TX_LANE0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE3_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE3_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE2_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE2_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE1_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE0_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE0_MASK
value|I40E_MASK(0x3, I40E_PRTMAC_PCS_XAUI_SWAP_B_SWAP_RX_LANE0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWRESETCNT
value|0x00083100
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FWRESETCNT_FWRESETCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FWRESETCNT_FWRESETCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FWRESETCNT_FWRESETCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM
value|0x000B6134
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_FW_MODES_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_FW_MODES_MASK
value|I40E_MASK(0x3, I40E_GL_MNG_FWSM_FW_MODES_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_EEP_RELOAD_IND_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_EEP_RELOAD_IND_MASK
value|I40E_MASK(0x1, I40E_GL_MNG_FWSM_EEP_RELOAD_IND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_CRC_ERROR_MODULE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_CRC_ERROR_MODULE_MASK
value|I40E_MASK(0xF, I40E_GL_MNG_FWSM_CRC_ERROR_MODULE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_FW_STATUS_VALID_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_FW_STATUS_VALID_MASK
value|I40E_MASK(0x1, I40E_GL_MNG_FWSM_FW_STATUS_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_RESET_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_RESET_CNT_MASK
value|I40E_MASK(0x7, I40E_GL_MNG_FWSM_RESET_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_EXT_ERR_IND_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_EXT_ERR_IND_MASK
value|I40E_MASK(0x3F, I40E_GL_MNG_FWSM_EXT_ERR_IND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES0_CONFIG_ERR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES0_CONFIG_ERR_MASK
value|I40E_MASK(0x1, I40E_GL_MNG_FWSM_PHY_SERDES0_CONFIG_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES1_CONFIG_ERR_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES1_CONFIG_ERR_MASK
value|I40E_MASK(0x1, I40E_GL_MNG_FWSM_PHY_SERDES1_CONFIG_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES2_CONFIG_ERR_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES2_CONFIG_ERR_MASK
value|I40E_MASK(0x1, I40E_GL_MNG_FWSM_PHY_SERDES2_CONFIG_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES3_CONFIG_ERR_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_FWSM_PHY_SERDES3_CONFIG_ERR_MASK
value|I40E_MASK(0x1, I40E_GL_MNG_FWSM_PHY_SERDES3_CONFIG_ERR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_HWARB_CTRL
value|0x000B6130
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_MNG_HWARB_CTRL_NCSI_ARB_EN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_MNG_HWARB_CTRL_NCSI_ARB_EN_MASK
value|I40E_MASK(0x1, I40E_GL_MNG_HWARB_CTRL_NCSI_ARB_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_DATA
parameter_list|(
name|_i
parameter_list|)
value|(0x000852A0 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...31 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_DATA_MAX_INDEX
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_DATA_DWORD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_DATA_DWORD_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRT_MNG_FTFT_DATA_DWORD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_LENGTH
value|0x00085260
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_LENGTH_LENGTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_LENGTH_LENGTH_MASK
value|I40E_MASK(0xFF, I40E_PRT_MNG_FTFT_LENGTH_LENGTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_MASK
parameter_list|(
name|_i
parameter_list|)
value|(0x00085160 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_MASK_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_MASK_MASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_FTFT_MASK_MASK_MASK
value|I40E_MASK(0xFFFF, I40E_PRT_MNG_FTFT_MASK_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC
value|0x00256A20
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_FLOW_CONTROL_DISCARD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_FLOW_CONTROL_DISCARD_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_FLOW_CONTROL_DISCARD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_NCSI_DISCARD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_NCSI_DISCARD_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_NCSI_DISCARD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_RCV_TCO_EN_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_RCV_TCO_EN_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_RCV_TCO_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_RCV_ALL_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_RCV_ALL_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_RCV_ALL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_FIXED_NET_TYPE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_FIXED_NET_TYPE_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_FIXED_NET_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_NET_TYPE_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_NET_TYPE_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_NET_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_EN_BMC2OS_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_EN_BMC2OS_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_EN_BMC2OS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_EN_BMC2NET_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MANC_EN_BMC2NET_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MANC_EN_BMC2NET_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MAVTV
parameter_list|(
name|_i
parameter_list|)
value|(0x00255900 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MAVTV_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MAVTV_VID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MAVTV_VID_MASK
value|I40E_MASK(0xFFF, I40E_PRT_MNG_MAVTV_VID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF
parameter_list|(
name|_i
parameter_list|)
value|(0x00255D00 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_MAC_EXACT_AND_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_MAC_EXACT_AND_MASK
value|I40E_MASK(0xF, I40E_PRT_MNG_MDEF_MAC_EXACT_AND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_BROADCAST_AND_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_BROADCAST_AND_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_BROADCAST_AND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_VLAN_AND_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_VLAN_AND_MASK
value|I40E_MASK(0xFF, I40E_PRT_MNG_MDEF_VLAN_AND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_IPV4_ADDRESS_AND_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_IPV4_ADDRESS_AND_MASK
value|I40E_MASK(0xF, I40E_PRT_MNG_MDEF_IPV4_ADDRESS_AND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_IPV6_ADDRESS_AND_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_IPV6_ADDRESS_AND_MASK
value|I40E_MASK(0xF, I40E_PRT_MNG_MDEF_IPV6_ADDRESS_AND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_MAC_EXACT_OR_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_MAC_EXACT_OR_MASK
value|I40E_MASK(0xF, I40E_PRT_MNG_MDEF_MAC_EXACT_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_BROADCAST_OR_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_BROADCAST_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_BROADCAST_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_MULTICAST_AND_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_MULTICAST_AND_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_MULTICAST_AND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_ARP_REQUEST_OR_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_ARP_REQUEST_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_ARP_REQUEST_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_ARP_RESPONSE_OR_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_ARP_RESPONSE_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_ARP_RESPONSE_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_NEIGHBOR_DISCOVERY_134_OR_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_NEIGHBOR_DISCOVERY_134_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_NEIGHBOR_DISCOVERY_134_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_PORT_0X298_OR_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_PORT_0X298_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_PORT_0X298_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_PORT_0X26F_OR_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_PORT_0X26F_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_PORT_0X26F_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT
parameter_list|(
name|_i
parameter_list|)
value|(0x00255F00 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_L2_ETHERTYPE_AND_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_L2_ETHERTYPE_AND_MASK
value|I40E_MASK(0xF, I40E_PRT_MNG_MDEF_EXT_L2_ETHERTYPE_AND_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_L2_ETHERTYPE_OR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_L2_ETHERTYPE_OR_MASK
value|I40E_MASK(0xF, I40E_PRT_MNG_MDEF_EXT_L2_ETHERTYPE_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_FLEX_PORT_OR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_FLEX_PORT_OR_MASK
value|I40E_MASK(0xFFFF, I40E_PRT_MNG_MDEF_EXT_FLEX_PORT_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_FLEX_TCO_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_FLEX_TCO_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_FLEX_TCO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_135_OR_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_135_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_135_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_136_OR_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_136_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_136_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_137_OR_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_137_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_NEIGHBOR_DISCOVERY_137_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_ICMP_OR_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_ICMP_OR_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_ICMP_OR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_MLD_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_MLD_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_MLD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_APPLY_TO_NETWORK_TRAFFIC_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_APPLY_TO_NETWORK_TRAFFIC_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_APPLY_TO_NETWORK_TRAFFIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_APPLY_TO_HOST_TRAFFIC_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEF_EXT_APPLY_TO_HOST_TRAFFIC_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MDEF_EXT_APPLY_TO_HOST_TRAFFIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEFVSI
parameter_list|(
name|_i
parameter_list|)
value|(0x00256580 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEFVSI_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEFVSI_MDEFVSI_2N_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEFVSI_MDEFVSI_2N_MASK
value|I40E_MASK(0xFFFF, I40E_PRT_MNG_MDEFVSI_MDEFVSI_2N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEFVSI_MDEFVSI_2NP1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MDEFVSI_MDEFVSI_2NP1_MASK
value|I40E_MASK(0xFFFF, I40E_PRT_MNG_MDEFVSI_MDEFVSI_2NP1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_METF
parameter_list|(
name|_i
parameter_list|)
value|(0x00256780 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_METF_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_METF_ETYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_METF_ETYPE_MASK
value|I40E_MASK(0xFFFF, I40E_PRT_MNG_METF_ETYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_METF_POLARITY_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_METF_POLARITY_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_METF_POLARITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP
parameter_list|(
name|_i
parameter_list|)
value|(0x00254E00 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_MFUTP_N_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_MFUTP_N_MASK
value|I40E_MASK(0xFFFF, I40E_PRT_MNG_MFUTP_MFUTP_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_UDP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_UDP_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MFUTP_UDP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_TCP_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_TCP_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MFUTP_TCP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_SOURCE_DESTINATION_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MFUTP_SOURCE_DESTINATION_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MFUTP_SOURCE_DESTINATION_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF4
parameter_list|(
name|_i
parameter_list|)
value|(0x00256280 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF4_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF4_MIPAF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF4_MIPAF_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRT_MNG_MIPAF4_MIPAF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF6
parameter_list|(
name|_i
parameter_list|)
value|(0x00254200 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF6_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF6_MIPAF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MIPAF6_MIPAF_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRT_MNG_MIPAF6_MIPAF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAH
parameter_list|(
name|_i
parameter_list|)
value|(0x00256380 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAH_MMAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAH_MMAH_MASK
value|I40E_MASK(0xFFFF, I40E_PRT_MNG_MMAH_MMAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAL
parameter_list|(
name|_i
parameter_list|)
value|(0x00256480 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAL_MMAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MMAL_MMAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRT_MNG_MMAL_MMAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MNGONLY
value|0x00256A60
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MNGONLY_EXCLUSIVE_TO_MANAGEABILITY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MNGONLY_EXCLUSIVE_TO_MANAGEABILITY_MASK
value|I40E_MASK(0xFF, I40E_PRT_MNG_MNGONLY_EXCLUSIVE_TO_MANAGEABILITY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM
value|0x00256AA0
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_26F_UDP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_26F_UDP_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_PORT_26F_UDP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_26F_TCP_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_26F_TCP_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_PORT_26F_TCP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_298_UDP_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_298_UDP_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_PORT_298_UDP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_298_TCP_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_PORT_298_TCP_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_PORT_298_TCP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_0_MASK_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_0_MASK_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_IPV6_0_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_1_MASK_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_1_MASK_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_IPV6_1_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_2_MASK_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_2_MASK_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_IPV6_2_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_3_MASK_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRT_MNG_MSFM_IPV6_3_MASK_MASK
value|I40E_MASK(0x1, I40E_PRT_MNG_MSFM_IPV6_3_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_PBA
parameter_list|(
name|_i
parameter_list|)
value|(0x00001000 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...5 */
end_comment

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_MSIX_PBA_MAX_INDEX
value|5
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_PBA_PENBIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_PBA_PENBIT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_MSIX_PBA_PENBIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TADD
parameter_list|(
name|_i
parameter_list|)
value|(0x00000000 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...128 */
end_comment

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_MSIX_TADD_MAX_INDEX
value|128
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TADD_MSIXTADD10_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TADD_MSIXTADD10_MASK
value|I40E_MASK(0x3, I40E_MSIX_TADD_MSIXTADD10_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TADD_MSIXTADD_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TADD_MSIXTADD_MASK
value|I40E_MASK(0x3FFFFFFF, I40E_MSIX_TADD_MSIXTADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TMSG
parameter_list|(
name|_i
parameter_list|)
value|(0x00000008 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...128 */
end_comment

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_MSIX_TMSG_MAX_INDEX
value|128
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TMSG_MSIXTMSG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TMSG_MSIXTMSG_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_MSIX_TMSG_MSIXTMSG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TUADD
parameter_list|(
name|_i
parameter_list|)
value|(0x00000004 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...128 */
end_comment

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_MSIX_TUADD_MAX_INDEX
value|128
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TUADD_MSIXTUADD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TUADD_MSIXTUADD_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_MSIX_TUADD_MSIXTUADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TVCTRL
parameter_list|(
name|_i
parameter_list|)
value|(0x0000000C + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...128 */
end_comment

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_MSIX_TVCTRL_MAX_INDEX
value|128
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TVCTRL_MASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_MSIX_TVCTRL_MASK_MASK
value|I40E_MASK(0x1, I40E_MSIX_TVCTRL_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_PBA1
parameter_list|(
name|_i
parameter_list|)
value|(0x00002000 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...19 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_PBA1_MAX_INDEX
value|19
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_PBA1_PENBIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_PBA1_PENBIT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_PBA1_PENBIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD1
parameter_list|(
name|_i
parameter_list|)
value|(0x00002100 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...639 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD1_MAX_INDEX
value|639
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD1_MSIXTADD10_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD1_MSIXTADD10_MASK
value|I40E_MASK(0x3, I40E_VFMSIX_TADD1_MSIXTADD10_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD1_MSIXTADD_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD1_MSIXTADD_MASK
value|I40E_MASK(0x3FFFFFFF, I40E_VFMSIX_TADD1_MSIXTADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG1
parameter_list|(
name|_i
parameter_list|)
value|(0x00002108 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...639 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG1_MAX_INDEX
value|639
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG1_MSIXTMSG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG1_MSIXTMSG_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TMSG1_MSIXTMSG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD1
parameter_list|(
name|_i
parameter_list|)
value|(0x00002104 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...639 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD1_MAX_INDEX
value|639
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD1_MSIXTUADD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD1_MSIXTUADD_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TUADD1_MSIXTUADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL1
parameter_list|(
name|_i
parameter_list|)
value|(0x0000210C + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...639 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL1_MAX_INDEX
value|639
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL1_MASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL1_MASK_MASK
value|I40E_MASK(0x1, I40E_VFMSIX_TVCTRL1_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA
value|0x000B6108
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SCK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SCK_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_SCK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_CE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_CE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_CE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SI_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SI_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_SI_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SO_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SO_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_SO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_REQ_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_REQ_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_REQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_GNT_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_GNT_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_GNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_LOCKED_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_LOCKED_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_LOCKED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SADDR_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_SADDR_MASK
value|I40E_MASK(0x7FF, I40E_GLNVM_FLA_FL_SADDR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_BUSY_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_BUSY_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_BUSY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_DER_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLA_FL_DER_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLA_FL_DER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLASHID
value|0x000B6104
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLNVM_FLASHID_FLASHID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLASHID_FLASHID_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLNVM_FLASHID_FLASHID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLASHID_FLEEP_PERF_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_FLASHID_FLEEP_PERF_MASK
value|I40E_MASK(0x1, I40E_GLNVM_FLASHID_FLEEP_PERF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS
value|0x000B6100
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_NVM_PRES_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_NVM_PRES_MASK
value|I40E_MASK(0x1, I40E_GLNVM_GENS_NVM_PRES_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_SR_SIZE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_SR_SIZE_MASK
value|I40E_MASK(0x7, I40E_GLNVM_GENS_SR_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_BANK1VAL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_BANK1VAL_MASK
value|I40E_MASK(0x1, I40E_GLNVM_GENS_BANK1VAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_ALT_PRST_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_ALT_PRST_MASK
value|I40E_MASK(0x1, I40E_GLNVM_GENS_ALT_PRST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_FL_AUTO_RD_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_GENS_FL_AUTO_RD_MASK
value|I40E_MASK(0x1, I40E_GLNVM_GENS_FL_AUTO_RD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_PROTCSR
parameter_list|(
name|_i
parameter_list|)
value|(0x000B6010 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...59 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLNVM_PROTCSR_MAX_INDEX
value|59
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_PROTCSR_ADDR_BLOCK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_PROTCSR_ADDR_BLOCK_MASK
value|I40E_MASK(0xFFFFFF, I40E_GLNVM_PROTCSR_ADDR_BLOCK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL
value|0x000B6110
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_SRBUSY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_SRBUSY_MASK
value|I40E_MASK(0x1, I40E_GLNVM_SRCTL_SRBUSY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_ADDR_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_ADDR_MASK
value|I40E_MASK(0x7FFF, I40E_GLNVM_SRCTL_ADDR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_WRITE_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_WRITE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_SRCTL_WRITE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_START_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_START_MASK
value|I40E_MASK(0x1, I40E_GLNVM_SRCTL_START_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_DONE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRCTL_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_SRCTL_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRDATA
value|0x000B6114
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLNVM_SRDATA_WRDATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRDATA_WRDATA_MASK
value|I40E_MASK(0xFFFF, I40E_GLNVM_SRDATA_WRDATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRDATA_RDDATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_SRDATA_RDDATA_MASK
value|I40E_MASK(0xFFFF, I40E_GLNVM_SRDATA_RDDATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD
value|0x000B6008
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIR_DONE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIR_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_PCIR_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIRTL_DONE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIRTL_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_PCIRTL_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_LCB_DONE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_LCB_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_LCB_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_CORE_DONE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_CORE_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_CORE_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_GLOBAL_DONE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_GLOBAL_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_GLOBAL_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_POR_DONE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_POR_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_POR_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIE_ANA_DONE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIE_ANA_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_PCIE_ANA_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PHY_ANA_DONE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PHY_ANA_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_PHY_ANA_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_EMP_DONE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_EMP_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_EMP_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIALT_DONE_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_GLNVM_ULD_CONF_PCIALT_DONE_MASK
value|I40E_MASK(0x1, I40E_GLNVM_ULD_CONF_PCIALT_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_BYTCTH
value|0x0009C484
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_BYTCTH_PCI_COUNT_BW_BCT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_BYTCTH_PCI_COUNT_BW_BCT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_BYTCTH_PCI_COUNT_BW_BCT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_BYTCTL
value|0x0009C488
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_BYTCTL_PCI_COUNT_BW_BCT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_BYTCTL_PCI_COUNT_BW_BCT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_BYTCTL_PCI_COUNT_BW_BCT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPCTRL
value|0x000BE4A4
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPCTRL_VPD_EN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPCTRL_VPD_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPCTRL_VPD_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP
value|0x000BE4A8
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_PCIE_VER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_PCIE_VER_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_PCIE_VER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_LTR_EN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_LTR_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_LTR_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_TPH_EN_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_TPH_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_TPH_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ARI_EN_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ARI_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_ARI_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_IOV_EN_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_IOV_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_IOV_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ACS_EN_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ACS_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_ACS_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_SEC_EN_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_SEC_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_SEC_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ECRC_GEN_EN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ECRC_GEN_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_ECRC_GEN_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ECRC_CHK_EN_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_ECRC_CHK_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_ECRC_CHK_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_IDO_EN_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_IDO_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_IDO_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_MSI_MASK_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_MSI_MASK_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_MSI_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_CSR_CONF_EN_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_CSR_CONF_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_CSR_CONF_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_LOAD_SUBSYS_ID_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_LOAD_SUBSYS_ID_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_LOAD_SUBSYS_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_LOAD_DEV_ID_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CAPSUP_LOAD_DEV_ID_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CAPSUP_LOAD_DEV_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF
value|0x000BE4C0
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF_FLEX10_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF_FLEX10_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CNF_FLEX10_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF_WAKE_PIN_EN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF_WAKE_PIN_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CNF_WAKE_PIN_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2
value|0x000BE494
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_RO_DIS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_RO_DIS_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CNF2_RO_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_CACHELINE_SIZE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_CACHELINE_SIZE_MASK
value|I40E_MASK(0x1, I40E_GLPCI_CNF2_CACHELINE_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_MSI_X_PF_N_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_MSI_X_PF_N_MASK
value|I40E_MASK(0x7FF, I40E_GLPCI_CNF2_MSI_X_PF_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_MSI_X_VF_N_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_CNF2_MSI_X_VF_N_MASK
value|I40E_MASK(0x7FF, I40E_GLPCI_CNF2_MSI_X_VF_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_DREVID
value|0x0009C480
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_DREVID_DEFAULT_REVID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_DREVID_DEFAULT_REVID_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_DREVID_DEFAULT_REVID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1
value|0x0009C48C
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_0_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_COUNT_EN_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_1_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_1_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_COUNT_EN_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_2_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_2_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_COUNT_EN_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_3_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_EN_3_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_COUNT_EN_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_0_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_0_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_LBC_ENABLE_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_1_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_1_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_LBC_ENABLE_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_2_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_2_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_LBC_ENABLE_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_3_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_LBC_ENABLE_3_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_LBC_ENABLE_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_LAT_EN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_LAT_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_PCI_COUNT_LAT_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_LAT_EV_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_LAT_EV_MASK
value|I40E_MASK(0x1F, I40E_GLPCI_GSCL_1_PCI_COUNT_LAT_EV_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_BW_EN_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_BW_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_PCI_COUNT_BW_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_BW_EV_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_PCI_COUNT_BW_EV_MASK
value|I40E_MASK(0x1F, I40E_GLPCI_GSCL_1_PCI_COUNT_BW_EV_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_64_BIT_EN_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_64_BIT_EN_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_64_BIT_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_RESET_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_RESET_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_COUNT_RESET_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_STOP_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_STOP_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_COUNT_STOP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_START_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_1_GIO_COUNT_START_MASK
value|I40E_MASK(0x1, I40E_GLPCI_GSCL_1_GIO_COUNT_START_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2
value|0x0009C490
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_0_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_1_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_2_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_3_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_GSCL_2_GIO_EVENT_NUM_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_5_8
parameter_list|(
name|_i
parameter_list|)
value|(0x0009C494 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_5_8_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_5_8_LBC_THRESHOLD_N_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_5_8_LBC_THRESHOLD_N_MASK
value|I40E_MASK(0xFFFF, I40E_GLPCI_GSCL_5_8_LBC_THRESHOLD_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_5_8_LBC_TIMER_N_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCL_5_8_LBC_TIMER_N_MASK
value|I40E_MASK(0xFFFF, I40E_GLPCI_GSCL_5_8_LBC_TIMER_N_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCN_0_3
parameter_list|(
name|_i
parameter_list|)
value|(0x0009C4A4 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCN_0_3_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCN_0_3_EVENT_COUNTER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_GSCN_0_3_EVENT_COUNTER_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_GSCN_0_3_EVENT_COUNTER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LATCT
value|0x0009C4B4
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_LATCT_PCI_COUNT_LAT_CT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LATCT_PCI_COUNT_LAT_CT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_LATCT_PCI_COUNT_LAT_CT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL
value|0x000BE484
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_PREFBAR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_PREFBAR_MASK
value|I40E_MASK(0x1, I40E_GLPCI_LBARCTRL_PREFBAR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_BAR32_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_BAR32_MASK
value|I40E_MASK(0x1, I40E_GLPCI_LBARCTRL_BAR32_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_FLASH_EXPOSE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_FLASH_EXPOSE_MASK
value|I40E_MASK(0x1, I40E_GLPCI_LBARCTRL_FLASH_EXPOSE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_RSVD_4_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_RSVD_4_MASK
value|I40E_MASK(0x3, I40E_GLPCI_LBARCTRL_RSVD_4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_FL_SIZE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_FL_SIZE_MASK
value|I40E_MASK(0x7, I40E_GLPCI_LBARCTRL_FL_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_RSVD_10_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_RSVD_10_MASK
value|I40E_MASK(0x1, I40E_GLPCI_LBARCTRL_RSVD_10_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_EXROM_SIZE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LBARCTRL_EXROM_SIZE_MASK
value|I40E_MASK(0x7, I40E_GLPCI_LBARCTRL_EXROM_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LINKCAP
value|0x000BE4AC
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_LINKCAP_LINK_SPEEDS_VECTOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LINKCAP_LINK_SPEEDS_VECTOR_MASK
value|I40E_MASK(0x3F, I40E_GLPCI_LINKCAP_LINK_SPEEDS_VECTOR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LINKCAP_MAX_PAYLOAD_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LINKCAP_MAX_PAYLOAD_MASK
value|I40E_MASK(0x7, I40E_GLPCI_LINKCAP_MAX_PAYLOAD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LINKCAP_MAX_LINK_WIDTH_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_LINKCAP_MAX_LINK_WIDTH_MASK
value|I40E_MASK(0xF, I40E_GLPCI_LINKCAP_MAX_LINK_WIDTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PCIERR
value|0x000BE4FC
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_PCIERR_PCIE_ERR_REP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PCIERR_PCIE_ERR_REP_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_PCIERR_PCIE_ERR_REP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PKTCT
value|0x0009C4BC
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_PKTCT_PCI_COUNT_BW_PCT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PKTCT_PCI_COUNT_BW_PCT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_PKTCT_PCI_COUNT_BW_PCT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_NPQ
value|0x0009C4F4
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_NPQ_NPQ_NUM_PORT_SEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_NPQ_NPQ_NUM_PORT_SEL_MASK
value|I40E_MASK(0x7, I40E_GLPCI_PM_MUX_NPQ_NPQ_NUM_PORT_SEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_NPQ_INNER_NPQ_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_NPQ_INNER_NPQ_SEL_MASK
value|I40E_MASK(0x1F, I40E_GLPCI_PM_MUX_NPQ_INNER_NPQ_SEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_PFB
value|0x0009C4F0
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_PFB_PFB_PORT_SEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_PFB_PFB_PORT_SEL_MASK
value|I40E_MASK(0x1F, I40E_GLPCI_PM_MUX_PFB_PFB_PORT_SEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_PFB_INNER_PORT_SEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PM_MUX_PFB_INNER_PORT_SEL_MASK
value|I40E_MASK(0x7, I40E_GLPCI_PM_MUX_PFB_INNER_PORT_SEL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP
value|0x000BE4B0
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_ASPM_SUP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_ASPM_SUP_MASK
value|I40E_MASK(0x3, I40E_GLPCI_PMSUP_ASPM_SUP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L0S_EXIT_LAT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L0S_EXIT_LAT_MASK
value|I40E_MASK(0x7, I40E_GLPCI_PMSUP_L0S_EXIT_LAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L1_EXIT_LAT_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L1_EXIT_LAT_MASK
value|I40E_MASK(0x7, I40E_GLPCI_PMSUP_L1_EXIT_LAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L0S_ACC_LAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L0S_ACC_LAT_MASK
value|I40E_MASK(0x7, I40E_GLPCI_PMSUP_L0S_ACC_LAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L1_ACC_LAT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_L1_ACC_LAT_MASK
value|I40E_MASK(0x7, I40E_GLPCI_PMSUP_L1_ACC_LAT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_SLOT_CLK_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_SLOT_CLK_MASK
value|I40E_MASK(0x1, I40E_GLPCI_PMSUP_SLOT_CLK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_OBFF_SUP_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PMSUP_OBFF_SUP_MASK
value|I40E_MASK(0x3, I40E_GLPCI_PMSUP_OBFF_SUP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PQ_MAX_USED_SPC
value|0x0009C4EC
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_PQ_MAX_USED_SPC_GLPCI_PQ_MAX_USED_SPC_12_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PQ_MAX_USED_SPC_GLPCI_PQ_MAX_USED_SPC_12_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_PQ_MAX_USED_SPC_GLPCI_PQ_MAX_USED_SPC_12_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PQ_MAX_USED_SPC_GLPCI_PQ_MAX_USED_SPC_13_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PQ_MAX_USED_SPC_GLPCI_PQ_MAX_USED_SPC_13_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_PQ_MAX_USED_SPC_GLPCI_PQ_MAX_USED_SPC_13_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA
value|0x000BE490
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_D0_POWER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_D0_POWER_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_PWRDATA_D0_POWER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_COMM_POWER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_COMM_POWER_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_PWRDATA_COMM_POWER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_D3_POWER_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_D3_POWER_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_PWRDATA_D3_POWER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_DATA_SCALE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_PWRDATA_DATA_SCALE_MASK
value|I40E_MASK(0x3, I40E_GLPCI_PWRDATA_DATA_SCALE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_REVID
value|0x000BE4B4
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_REVID_NVM_REVID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_REVID_NVM_REVID_MASK
value|I40E_MASK(0xFF, I40E_GLPCI_REVID_NVM_REVID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SERH
value|0x000BE49C
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_SERH_SER_NUM_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SERH_SER_NUM_H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPCI_SERH_SER_NUM_H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SERL
value|0x000BE498
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_SERL_SER_NUM_L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SERL_SER_NUM_L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_SERL_SER_NUM_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SPARE_BITS_0
value|0x0009C4F8
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_SPARE_BITS_0_SPARE_BITS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SPARE_BITS_0_SPARE_BITS_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_SPARE_BITS_0_SPARE_BITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SPARE_BITS_1
value|0x0009C4FC
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_SPARE_BITS_1_SPARE_BITS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SPARE_BITS_1_SPARE_BITS_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPCI_SPARE_BITS_1_SPARE_BITS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SUBVENID
value|0x000BE48C
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_SUBVENID_SUB_VEN_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_SUBVENID_SUB_VEN_ID_MASK
value|I40E_MASK(0xFFFF, I40E_GLPCI_SUBVENID_SUB_VEN_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_UPADD
value|0x000BE4F8
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_UPADD_ADDRESS_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_UPADD_ADDRESS_MASK
value|I40E_MASK(0x7FFFFFFF, I40E_GLPCI_UPADD_ADDRESS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_VENDORID
value|0x000BE518
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_VENDORID_VENDORID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_VENDORID_VENDORID_MASK
value|I40E_MASK(0xFFFF, I40E_GLPCI_VENDORID_VENDORID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_VFSUP
value|0x000BE4B8
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPCI_VFSUP_VF_PREFETCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_VFSUP_VF_PREFETCH_MASK
value|I40E_MASK(0x1, I40E_GLPCI_VFSUP_VF_PREFETCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_VFSUP_VR_BAR_TYPE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLPCI_VFSUP_VR_BAR_TYPE_MASK
value|I40E_MASK(0x1, I40E_GLPCI_VFSUP_VR_BAR_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_FUNC_RID
value|0x0009C000
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_FUNC_RID_FUNCTION_NUMBER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_FUNC_RID_FUNCTION_NUMBER_MASK
value|I40E_MASK(0x7, I40E_PF_FUNC_RID_FUNCTION_NUMBER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_FUNC_RID_DEVICE_NUMBER_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PF_FUNC_RID_DEVICE_NUMBER_MASK
value|I40E_MASK(0x1F, I40E_PF_FUNC_RID_DEVICE_NUMBER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_FUNC_RID_BUS_NUMBER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PF_FUNC_RID_BUS_NUMBER_MASK
value|I40E_MASK(0xFF, I40E_PF_FUNC_RID_BUS_NUMBER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAA
value|0x0009C080
end_define

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAA_ADDRESS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAA_ADDRESS_MASK
value|I40E_MASK(0xFFF, I40E_PF_PCI_CIAA_ADDRESS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAA_VF_NUM_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAA_VF_NUM_MASK
value|I40E_MASK(0x7F, I40E_PF_PCI_CIAA_VF_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAD
value|0x0009C100
end_define

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAD_DATA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_PCI_CIAD_DATA_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PF_PCI_CIAD_DATA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CLASS
value|0x000BE400
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_CLASS_STORAGE_CLASS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CLASS_STORAGE_CLASS_MASK
value|I40E_MASK(0x1, I40E_PFPCI_CLASS_STORAGE_CLASS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CLASS_RESERVED_1_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CLASS_RESERVED_1_MASK
value|I40E_MASK(0x1, I40E_PFPCI_CLASS_RESERVED_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CLASS_PF_IS_LAN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CLASS_PF_IS_LAN_MASK
value|I40E_MASK(0x1, I40E_PFPCI_CLASS_PF_IS_LAN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF
value|0x000BE000
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_MSI_EN_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_MSI_EN_MASK
value|I40E_MASK(0x1, I40E_PFPCI_CNF_MSI_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_EXROM_DIS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_EXROM_DIS_MASK
value|I40E_MASK(0x1, I40E_PFPCI_CNF_EXROM_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_IO_BAR_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_IO_BAR_MASK
value|I40E_MASK(0x1, I40E_PFPCI_CNF_IO_BAR_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_INT_PIN_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_CNF_INT_PIN_MASK
value|I40E_MASK(0x3, I40E_PFPCI_CNF_INT_PIN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_DEVID
value|0x000BE080
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_DEVID_PF_DEV_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_DEVID_PF_DEV_ID_MASK
value|I40E_MASK(0xFFFF, I40E_PFPCI_DEVID_PF_DEV_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_DEVID_VF_DEV_ID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_DEVID_VF_DEV_ID_MASK
value|I40E_MASK(0xFFFF, I40E_PFPCI_DEVID_VF_DEV_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FACTPS
value|0x0009C180
end_define

begin_comment
comment|/* Reset: FLR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_FACTPS_FUNC_POWER_STATE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FACTPS_FUNC_POWER_STATE_MASK
value|I40E_MASK(0x3, I40E_PFPCI_FACTPS_FUNC_POWER_STATE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FACTPS_FUNC_AUX_EN_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FACTPS_FUNC_AUX_EN_MASK
value|I40E_MASK(0x1, I40E_PFPCI_FACTPS_FUNC_AUX_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC
value|0x000BE200
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC_FUNC_DIS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC_FUNC_DIS_MASK
value|I40E_MASK(0x1, I40E_PFPCI_FUNC_FUNC_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC_ALLOW_FUNC_DIS_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC_ALLOW_FUNC_DIS_MASK
value|I40E_MASK(0x1, I40E_PFPCI_FUNC_ALLOW_FUNC_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC_DIS_FUNC_ON_PORT_DIS_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC_DIS_FUNC_ON_PORT_DIS_MASK
value|I40E_MASK(0x1, I40E_PFPCI_FUNC_DIS_FUNC_ON_PORT_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC2
value|0x000BE180
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC2_EMP_FUNC_DIS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_FUNC2_EMP_FUNC_DIS_MASK
value|I40E_MASK(0x1, I40E_PFPCI_FUNC2_EMP_FUNC_DIS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_ICAUSE
value|0x0009C200
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_ICAUSE_PCIE_ERR_CAUSE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_ICAUSE_PCIE_ERR_CAUSE_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PFPCI_ICAUSE_PCIE_ERR_CAUSE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_IENA
value|0x0009C280
end_define

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_IENA_PCIE_ERR_EN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_IENA_PCIE_ERR_EN_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PFPCI_IENA_PCIE_ERR_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_PF_FLUSH_DONE
value|0x0009C800
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_PF_FLUSH_DONE_FLUSH_DONE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_PF_FLUSH_DONE_FLUSH_DONE_MASK
value|I40E_MASK(0x1, I40E_PFPCI_PF_FLUSH_DONE_FLUSH_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_PM
value|0x000BE300
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_PM_PME_EN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_PM_PME_EN_MASK
value|I40E_MASK(0x1, I40E_PFPCI_PM_PME_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_STATUS1
value|0x000BE280
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_STATUS1_FUNC_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_STATUS1_FUNC_VALID_MASK
value|I40E_MASK(0x1, I40E_PFPCI_STATUS1_FUNC_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_SUBSYSID
value|0x000BE100
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_SUBSYSID_PF_SUBSYS_ID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_SUBSYSID_PF_SUBSYS_ID_MASK
value|I40E_MASK(0xFFFF, I40E_PFPCI_SUBSYSID_PF_SUBSYS_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_SUBSYSID_VF_SUBSYS_ID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_SUBSYSID_VF_SUBSYS_ID_MASK
value|I40E_MASK(0xFFFF, I40E_PFPCI_SUBSYSID_VF_SUBSYS_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VF_FLUSH_DONE
value|0x0000E400
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_VF_FLUSH_DONE_FLUSH_DONE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VF_FLUSH_DONE_FLUSH_DONE_MASK
value|I40E_MASK(0x1, I40E_PFPCI_VF_FLUSH_DONE_FLUSH_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VF_FLUSH_DONE1
parameter_list|(
name|_VF
parameter_list|)
value|(0x0009C600 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_VF_FLUSH_DONE1_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VF_FLUSH_DONE1_FLUSH_DONE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VF_FLUSH_DONE1_FLUSH_DONE_MASK
value|I40E_MASK(0x1, I40E_PFPCI_VF_FLUSH_DONE1_FLUSH_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VM_FLUSH_DONE
value|0x0009C880
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_VM_FLUSH_DONE_FLUSH_DONE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VM_FLUSH_DONE_FLUSH_DONE_MASK
value|I40E_MASK(0x1, I40E_PFPCI_VM_FLUSH_DONE_FLUSH_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VMINDEX
value|0x0009C300
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_VMINDEX_VMINDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VMINDEX_VMINDEX_MASK
value|I40E_MASK(0x1FF, I40E_PFPCI_VMINDEX_VMINDEX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VMPEND
value|0x0009C380
end_define

begin_comment
comment|/* Reset: PCIR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPCI_VMPEND_PENDING_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPCI_VMPEND_PENDING_MASK
value|I40E_MASK(0x1, I40E_PFPCI_VMPEND_PENDING_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEE_STAT
value|0x001E4320
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_EEE_STAT_EEE_NEG_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEE_STAT_EEE_NEG_MASK
value|I40E_MASK(0x1, I40E_PRTPM_EEE_STAT_EEE_NEG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEE_STAT_RX_LPI_STATUS_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEE_STAT_RX_LPI_STATUS_MASK
value|I40E_MASK(0x1, I40E_PRTPM_EEE_STAT_RX_LPI_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEE_STAT_TX_LPI_STATUS_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEE_STAT_TX_LPI_STATUS_MASK
value|I40E_MASK(0x1, I40E_PRTPM_EEE_STAT_TX_LPI_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEC
value|0x001E4380
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEC_TW_WAKE_MIN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEC_TW_WAKE_MIN_MASK
value|I40E_MASK(0x3F, I40E_PRTPM_EEEC_TW_WAKE_MIN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEC_TX_LU_LPI_DLY_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEC_TX_LU_LPI_DLY_MASK
value|I40E_MASK(0x3, I40E_PRTPM_EEEC_TX_LU_LPI_DLY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEC_TEEE_DLY_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEC_TEEE_DLY_MASK
value|I40E_MASK(0x3F, I40E_PRTPM_EEEC_TEEE_DLY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEFWD
value|0x001E4400
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEFWD_EEE_FW_CONFIG_DONE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEEFWD_EEE_FW_CONFIG_DONE_MASK
value|I40E_MASK(0x1, I40E_PRTPM_EEEFWD_EEE_FW_CONFIG_DONE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEER
value|0x001E4360
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_EEER_TW_SYSTEM_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEER_TW_SYSTEM_MASK
value|I40E_MASK(0xFFFF, I40E_PRTPM_EEER_TW_SYSTEM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEER_TX_LPI_EN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEER_TX_LPI_EN_MASK
value|I40E_MASK(0x1, I40E_PRTPM_EEER_TX_LPI_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEETXC
value|0x001E43E0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_EEETXC_TW_PHY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_EEETXC_TW_PHY_MASK
value|I40E_MASK(0xFFFF, I40E_PRTPM_EEETXC_TW_PHY_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC
value|0x000B8140
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_EMP_LINK_ON_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_EMP_LINK_ON_MASK
value|I40E_MASK(0x1, I40E_PRTPM_GC_EMP_LINK_ON_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_MNG_VETO_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_MNG_VETO_MASK
value|I40E_MASK(0x1, I40E_PRTPM_GC_MNG_VETO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_RATD_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_RATD_MASK
value|I40E_MASK(0x1, I40E_PRTPM_GC_RATD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_LCDMP_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_LCDMP_MASK
value|I40E_MASK(0x1, I40E_PRTPM_GC_LCDMP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_LPLU_ASSERTED_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_GC_LPLU_ASSERTED_MASK
value|I40E_MASK(0x1, I40E_PRTPM_GC_LPLU_ASSERTED_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_RLPIC
value|0x001E43A0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_RLPIC_ERLPIC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_RLPIC_ERLPIC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTPM_RLPIC_ERLPIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_TLPIC
value|0x001E43C0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_TLPIC_ETLPIC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_TLPIC_ETLPIC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTPM_TLPIC_ETLPIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_DPSS
value|0x000AC828
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLRPB_DPSS_DPS_TCN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_DPSS_DPS_TCN_MASK
value|I40E_MASK(0xFFFFF, I40E_GLRPB_DPSS_DPS_TCN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_GHW
value|0x000AC830
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLRPB_GHW_GHW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_GHW_GHW_MASK
value|I40E_MASK(0xFFFFF, I40E_GLRPB_GHW_GHW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_GLW
value|0x000AC834
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLRPB_GLW_GLW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_GLW_GLW_MASK
value|I40E_MASK(0xFFFFF, I40E_GLRPB_GLW_GLW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_PHW
value|0x000AC844
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLRPB_PHW_PHW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_PHW_PHW_MASK
value|I40E_MASK(0xFFFFF, I40E_GLRPB_PHW_PHW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_PLW
value|0x000AC848
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLRPB_PLW_PLW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLRPB_PLW_PLW_MASK
value|I40E_MASK(0xFFFFF, I40E_GLRPB_PLW_PLW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DHW
parameter_list|(
name|_i
parameter_list|)
value|(0x000AC100 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_DHW_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DHW_DHW_TCN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DHW_DHW_TCN_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_DHW_DHW_TCN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DLW
parameter_list|(
name|_i
parameter_list|)
value|(0x000AC220 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_DLW_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DLW_DLW_TCN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DLW_DLW_TCN_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_DLW_DLW_TCN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DPS
parameter_list|(
name|_i
parameter_list|)
value|(0x000AC320 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_DPS_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DPS_DPS_TCN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_DPS_DPS_TCN_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_DPS_DPS_TCN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SHT
parameter_list|(
name|_i
parameter_list|)
value|(0x000AC480 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_SHT_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SHT_SHT_TCN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SHT_SHT_TCN_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_SHT_SHT_TCN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SHW
value|0x000AC580
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_SHW_SHW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SHW_SHW_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_SHW_SHW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SLT
parameter_list|(
name|_i
parameter_list|)
value|(0x000AC5A0 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_SLT_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SLT_SLT_TCN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SLT_SLT_TCN_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_SLT_SLT_TCN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SLW
value|0x000AC6A0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_SLW_SLW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SLW_SLW_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_SLW_SLW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SPS
value|0x000AC7C0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTRPB_SPS_SPS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTRPB_SPS_SPS_MASK
value|I40E_MASK(0xFFFFF, I40E_PRTRPB_SPS_SPS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL
value|0x00269BA4
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_HTOEP_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_HTOEP_MASK
value|I40E_MASK(0x1, I40E_GLQF_CTL_HTOEP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_HTOEP_FCOE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_HTOEP_FCOE_MASK
value|I40E_MASK(0x1, I40E_GLQF_CTL_HTOEP_FCOE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_PCNT_ALLOC_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_PCNT_ALLOC_MASK
value|I40E_MASK(0x7, I40E_GLQF_CTL_PCNT_ALLOC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_FD_AUTO_PCTYPE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_FD_AUTO_PCTYPE_MASK
value|I40E_MASK(0x1, I40E_GLQF_CTL_FD_AUTO_PCTYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_RSVD_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_RSVD_MASK
value|I40E_MASK(0x1, I40E_GLQF_CTL_RSVD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_MAXPEBLEN_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_MAXPEBLEN_MASK
value|I40E_MASK(0x7, I40E_GLQF_CTL_MAXPEBLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_MAXFCBLEN_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_MAXFCBLEN_MASK
value|I40E_MASK(0x7, I40E_GLQF_CTL_MAXFCBLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_MAXFDBLEN_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_MAXFDBLEN_MASK
value|I40E_MASK(0x7, I40E_GLQF_CTL_MAXFDBLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_FDBEST_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_FDBEST_MASK
value|I40E_MASK(0xFF, I40E_GLQF_CTL_FDBEST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_PROGPRIO_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_PROGPRIO_MASK
value|I40E_MASK(0x1, I40E_GLQF_CTL_PROGPRIO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_INVALPRIO_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_INVALPRIO_MASK
value|I40E_MASK(0x1, I40E_GLQF_CTL_INVALPRIO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_IGNORE_IP_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_CTL_IGNORE_IP_MASK
value|I40E_MASK(0x1, I40E_GLQF_CTL_IGNORE_IP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_FDCNT_0
value|0x00269BAC
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLQF_FDCNT_0_GUARANT_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_FDCNT_0_GUARANT_CNT_MASK
value|I40E_MASK(0x1FFF, I40E_GLQF_FDCNT_0_GUARANT_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_FDCNT_0_BESTCNT_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_FDCNT_0_BESTCNT_MASK
value|I40E_MASK(0x1FFF, I40E_GLQF_FDCNT_0_BESTCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY
parameter_list|(
name|_i
parameter_list|)
value|(0x00270140 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...12 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_MAX_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_0_MASK
value|I40E_MASK(0xFF, I40E_GLQF_HKEY_KEY_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_1_MASK
value|I40E_MASK(0xFF, I40E_GLQF_HKEY_KEY_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_2_MASK
value|I40E_MASK(0xFF, I40E_GLQF_HKEY_KEY_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HKEY_KEY_3_MASK
value|I40E_MASK(0xFF, I40E_GLQF_HKEY_KEY_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HSYM
parameter_list|(
name|_i
parameter_list|)
value|(0x00269D00 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...63 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLQF_HSYM_MAX_INDEX
value|63
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HSYM_SYMH_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_HSYM_SYMH_ENA_MASK
value|I40E_MASK(0x1, I40E_GLQF_HSYM_SYMH_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_PCNT
parameter_list|(
name|_i
parameter_list|)
value|(0x00266800 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...511 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLQF_PCNT_MAX_INDEX
value|511
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_PCNT_PCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_PCNT_PCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLQF_PCNT_PCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00267E00 + ((_i) * 4 + (_j) * 8))
end_define

begin_comment
comment|/* _i=0...1, _j=0...63 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF0_SRC0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF0_SRC0_MASK
value|I40E_MASK(0x3F, I40E_GLQF_SWAP_OFF0_SRC0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF0_SRC1_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF0_SRC1_MASK
value|I40E_MASK(0x3F, I40E_GLQF_SWAP_OFF0_SRC1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_FLEN0_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_FLEN0_MASK
value|I40E_MASK(0xF, I40E_GLQF_SWAP_FLEN0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF1_SRC0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF1_SRC0_MASK
value|I40E_MASK(0x3F, I40E_GLQF_SWAP_OFF1_SRC0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF1_SRC1_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_OFF1_SRC1_MASK
value|I40E_MASK(0x3F, I40E_GLQF_SWAP_OFF1_SRC1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_FLEN1_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_GLQF_SWAP_FLEN1_MASK
value|I40E_MASK(0xF, I40E_GLQF_SWAP_FLEN1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0
value|0x001C0AC0
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PEHSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PEHSIZE_MASK
value|I40E_MASK(0x1F, I40E_PFQF_CTL_0_PEHSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PEDSIZE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PEDSIZE_MASK
value|I40E_MASK(0x1F, I40E_PFQF_CTL_0_PEDSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PFFCHSIZE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PFFCHSIZE_MASK
value|I40E_MASK(0xF, I40E_PFQF_CTL_0_PFFCHSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PFFCDSIZE_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_PFFCDSIZE_MASK
value|I40E_MASK(0x3, I40E_PFQF_CTL_0_PFFCDSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_HASHLUTSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_HASHLUTSIZE_MASK
value|I40E_MASK(0x1, I40E_PFQF_CTL_0_HASHLUTSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_FD_ENA_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_FD_ENA_MASK
value|I40E_MASK(0x1, I40E_PFQF_CTL_0_FD_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_ETYPE_ENA_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_ETYPE_ENA_MASK
value|I40E_MASK(0x1, I40E_PFQF_CTL_0_ETYPE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_MACVLAN_ENA_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_MACVLAN_ENA_MASK
value|I40E_MASK(0x1, I40E_PFQF_CTL_0_MACVLAN_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_VFFCHSIZE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_VFFCHSIZE_MASK
value|I40E_MASK(0xF, I40E_PFQF_CTL_0_VFFCHSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_VFFCDSIZE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_0_VFFCDSIZE_MASK
value|I40E_MASK(0x3, I40E_PFQF_CTL_0_VFFCDSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_1
value|0x00245D80
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_1_CLEARFDTABLE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_CTL_1_CLEARFDTABLE_MASK
value|I40E_MASK(0x1, I40E_PFQF_CTL_1_CLEARFDTABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDALLOC
value|0x00246280
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_FDALLOC_FDALLOC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDALLOC_FDALLOC_MASK
value|I40E_MASK(0xFF, I40E_PFQF_FDALLOC_FDALLOC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDALLOC_FDBEST_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDALLOC_FDBEST_MASK
value|I40E_MASK(0xFF, I40E_PFQF_FDALLOC_FDBEST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDSTAT
value|0x00246380
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_FDSTAT_GUARANT_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDSTAT_GUARANT_CNT_MASK
value|I40E_MASK(0x1FFF, I40E_PFQF_FDSTAT_GUARANT_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDSTAT_BEST_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_FDSTAT_BEST_CNT_MASK
value|I40E_MASK(0x1FFF, I40E_PFQF_FDSTAT_BEST_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HENA
parameter_list|(
name|_i
parameter_list|)
value|(0x00245900 + ((_i) * 128))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_HENA_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HENA_PTYPE_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HENA_PTYPE_ENA_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PFQF_HENA_PTYPE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY
parameter_list|(
name|_i
parameter_list|)
value|(0x00244800 + ((_i) * 128))
end_define

begin_comment
comment|/* _i=0...12 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_MAX_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_0_MASK
value|I40E_MASK(0xFF, I40E_PFQF_HKEY_KEY_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_1_MASK
value|I40E_MASK(0xFF, I40E_PFQF_HKEY_KEY_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_2_MASK
value|I40E_MASK(0xFF, I40E_PFQF_HKEY_KEY_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HKEY_KEY_3_MASK
value|I40E_MASK(0xFF, I40E_PFQF_HKEY_KEY_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT
parameter_list|(
name|_i
parameter_list|)
value|(0x00240000 + ((_i) * 128))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT0_MASK
value|I40E_MASK(0x3F, I40E_PFQF_HLUT_LUT0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT1_MASK
value|I40E_MASK(0x3F, I40E_PFQF_HLUT_LUT1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT2_MASK
value|I40E_MASK(0x3F, I40E_PFQF_HLUT_LUT2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PFQF_HLUT_LUT3_MASK
value|I40E_MASK(0x3F, I40E_PFQF_HLUT_LUT3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_CTL_0
value|0x00256E60
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTQF_CTL_0_HSYM_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_CTL_0_HSYM_ENA_MASK
value|I40E_MASK(0x1, I40E_PRTQF_CTL_0_HSYM_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_FLXINSET
parameter_list|(
name|_i
parameter_list|)
value|(0x00253800 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...63 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_FLXINSET_MAX_INDEX
value|63
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_FLXINSET_INSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_FLXINSET_INSET_MASK
value|I40E_MASK(0xFF, I40E_PRTQF_FD_FLXINSET_INSET_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_MSK
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00252000 + ((_i) * 64 + (_j) * 32))
end_define

begin_comment
comment|/* _i=0...63, _j=0...1 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_MSK_MAX_INDEX
value|63
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_MSK_MASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_MSK_MASK_MASK
value|I40E_MASK(0xFFFF, I40E_PRTQF_FD_MSK_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_MSK_OFFSET_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FD_MSK_OFFSET_MASK
value|I40E_MASK(0x3F, I40E_PRTQF_FD_MSK_OFFSET_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT
parameter_list|(
name|_i
parameter_list|)
value|(0x00255200 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...8 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT_MAX_INDEX
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT_SOURCE_OFF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT_SOURCE_OFF_MASK
value|I40E_MASK(0x1F, I40E_PRTQF_FLX_PIT_SOURCE_OFF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT_FSIZE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT_FSIZE_MASK
value|I40E_MASK(0x1F, I40E_PRTQF_FLX_PIT_FSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT_DEST_OFF_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_PRTQF_FLX_PIT_DEST_OFF_MASK
value|I40E_MASK(0x3F, I40E_PRTQF_FLX_PIT_DEST_OFF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HENA1
parameter_list|(
name|_i
parameter_list|,
name|_VF
parameter_list|)
value|(0x00230800 + ((_i) * 1024 + (_VF) * 4))
end_define

begin_comment
comment|/* _i=0...1, _VF=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HENA1_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HENA1_PTYPE_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HENA1_PTYPE_ENA_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFQF_HENA1_PTYPE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1
parameter_list|(
name|_i
parameter_list|,
name|_VF
parameter_list|)
value|(0x00228000 + ((_i) * 1024 + (_VF) * 4))
end_define

begin_comment
comment|/* _i=0...12, _VF=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_MAX_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_0_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY1_KEY_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_1_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY1_KEY_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_2_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY1_KEY_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY1_KEY_3_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY1_KEY_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1
parameter_list|(
name|_i
parameter_list|,
name|_VF
parameter_list|)
value|(0x00220000 + ((_i) * 1024 + (_VF) * 4))
end_define

begin_comment
comment|/* _i=0...15, _VF=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT0_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT1_LUT0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT1_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT1_LUT1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT2_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT1_LUT2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT1_LUT3_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT1_LUT3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1
parameter_list|(
name|_i
parameter_list|,
name|_VF
parameter_list|)
value|(0x0022E000 + ((_i) * 1024 + (_VF) * 4))
end_define

begin_comment
comment|/* _i=0...7, _VF=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_0_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_0_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_0_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_1_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_1_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_1_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_2_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_2_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_2_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_3_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_3_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_3_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_4_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_4_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_4_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_4_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_5_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_5_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_5_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_5_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_6_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_6_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_6_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_6_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_7_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_OVERRIDE_ENA_7_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION1_OVERRIDE_ENA_7_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_7_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION1_REGION_7_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION1_REGION_7_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL
parameter_list|(
name|_VF
parameter_list|)
value|(0x001C0000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_PEHSIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_PEHSIZE_MASK
value|I40E_MASK(0x1F, I40E_VPQF_CTL_PEHSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_PEDSIZE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_PEDSIZE_MASK
value|I40E_MASK(0x1F, I40E_VPQF_CTL_PEDSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_FCHSIZE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_FCHSIZE_MASK
value|I40E_MASK(0xF, I40E_VPQF_CTL_FCHSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_FCDSIZE_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|I40E_VPQF_CTL_FCDSIZE_MASK
value|I40E_MASK(0x3, I40E_VPQF_CTL_FCDSIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL
parameter_list|(
name|_VSI
parameter_list|)
value|(0x0020D800 + ((_VSI) * 4))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_FCOE_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_FCOE_ENA_MASK
value|I40E_MASK(0x1, I40E_VSIQF_CTL_FCOE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PETCP_ENA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PETCP_ENA_MASK
value|I40E_MASK(0x1, I40E_VSIQF_CTL_PETCP_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEUUDP_ENA_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEUUDP_ENA_MASK
value|I40E_MASK(0x1, I40E_VSIQF_CTL_PEUUDP_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEMUDP_ENA_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEMUDP_ENA_MASK
value|I40E_MASK(0x1, I40E_VSIQF_CTL_PEMUDP_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEUFRAG_ENA_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEUFRAG_ENA_MASK
value|I40E_MASK(0x1, I40E_VSIQF_CTL_PEUFRAG_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEMFRAG_ENA_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_CTL_PEMFRAG_ENA_MASK
value|I40E_MASK(0x1, I40E_VSIQF_CTL_PEMFRAG_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION
parameter_list|(
name|_i
parameter_list|,
name|_VSI
parameter_list|)
value|(0x00206000 + ((_i) * 2048 + (_VSI) * 4))
end_define

begin_comment
comment|/* _i=0...3, _VSI=0...383 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_OFFSET_MASK
value|I40E_MASK(0x1FF, I40E_VSIQF_TCREGION_TC_OFFSET_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_SIZE_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_SIZE_MASK
value|I40E_MASK(0x7, I40E_VSIQF_TCREGION_TC_SIZE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_OFFSET2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_OFFSET2_MASK
value|I40E_MASK(0x1FF, I40E_VSIQF_TCREGION_TC_OFFSET2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_SIZE2_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VSIQF_TCREGION_TC_SIZE2_MASK
value|I40E_MASK(0x7, I40E_VSIQF_TCREGION_TC_SIZE2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOECRC
parameter_list|(
name|_i
parameter_list|)
value|(0x00314d80 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOECRC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOECRC_FCOECRC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOECRC_FCOECRC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOECRC_FCOECRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDDPC
parameter_list|(
name|_i
parameter_list|)
value|(0x00314480 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDDPC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDDPC_FCOEDDPC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDDPC_FCOEDDPC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEDDPC_FCOEDDPC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFEC
parameter_list|(
name|_i
parameter_list|)
value|(0x00318480 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFEC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFEC_FCOEDIFRC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFEC_FCOEDIFRC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEDIFEC_FCOEDIFRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00354000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFTCL_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFTCL_FCOEDIFTC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIFTCL_FCOEDIFTC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEDIFTCL_FCOEDIFTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXEC
parameter_list|(
name|_i
parameter_list|)
value|(0x0034c000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXEC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXEC_FCOEDIXEC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXEC_FCOEDIXEC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEDIXEC_FCOEDIXEC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXVC
parameter_list|(
name|_i
parameter_list|)
value|(0x00350000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXVC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXVC_FCOEDIXVC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDIXVC_FCOEDIXVC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEDIXVC_FCOEDIXVC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00320004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCH_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCH_FCOEDWRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCH_FCOEDWRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GL_FCOEDWRCH_FCOEDWRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00320000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCL_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCL_FCOEDWRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWRCL_FCOEDWRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEDWRCL_FCOEDWRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00348084 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCH_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCH_FCOEDWTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCH_FCOEDWTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GL_FCOEDWTCH_FCOEDWTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00348080 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCL_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCL_FCOEDWTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEDWTCL_FCOEDWTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEDWTCL_FCOEDWTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOELAST
parameter_list|(
name|_i
parameter_list|)
value|(0x00314000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOELAST_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOELAST_FCOELAST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOELAST_FCOELAST_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOELAST_FCOELAST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEPRC
parameter_list|(
name|_i
parameter_list|)
value|(0x00315200 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEPRC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEPRC_FCOEPRC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEPRC_FCOEPRC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEPRC_FCOEPRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEPTC
parameter_list|(
name|_i
parameter_list|)
value|(0x00344C00 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOEPTC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEPTC_FCOEPTC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOEPTC_FCOEPTC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOEPTC_FCOEPTC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOERPDC
parameter_list|(
name|_i
parameter_list|)
value|(0x00324000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_FCOERPDC_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOERPDC_FCOERPDC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_FCOERPDC_FCOERPDC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_FCOERPDC_FCOERPDC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_RXERR1_L
parameter_list|(
name|_i
parameter_list|)
value|(0x00318000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_RXERR1_L_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_RXERR1_L_FCOEDIFRC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_RXERR1_L_FCOEDIFRC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_RXERR1_L_FCOEDIFRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_RXERR2_L
parameter_list|(
name|_i
parameter_list|)
value|(0x0031c000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...143 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_RXERR2_L_MAX_INDEX
value|143
end_define

begin_define
define|#
directive|define
name|I40E_GL_RXERR2_L_FCOEDIXAC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_RXERR2_L_FCOEDIXAC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_RXERR2_L_FCOEDIXAC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x003005E4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCH_UPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCH_UPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_BPRCH_UPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x003005E0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCL_UPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPRCL_UPRCH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_BPRCL_UPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00300A04 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCH_UPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCH_UPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_BPTCH_UPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00300A00 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCL_UPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_BPTCL_UPRCH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_BPTCL_UPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_CRCERRS
parameter_list|(
name|_i
parameter_list|)
value|(0x00300080 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_CRCERRS_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_CRCERRS_CRCERRS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_CRCERRS_CRCERRS_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_CRCERRS_CRCERRS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00300004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCH_GORCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCH_GORCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_GORCH_GORCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00300000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCL_GORCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GORCL_GORCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_GORCL_GORCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00300684 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCH_GOTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCH_GOTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_GOTCH_GOTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00300680 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCL_GOTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_GOTCL_GOTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_GOTCL_GOTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_ILLERRC
parameter_list|(
name|_i
parameter_list|)
value|(0x003000E0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_ILLERRC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_ILLERRC_ILLERRC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_ILLERRC_ILLERRC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_ILLERRC_ILLERRC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LDPC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300620 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_LDPC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LDPC_LDPC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LDPC_LDPC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_LDPC_LDPC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFRXC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300160 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFRXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFRXC_LXOFFRXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFRXC_LXOFFRXCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_LXOFFRXC_LXOFFRXCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFTXC
parameter_list|(
name|_i
parameter_list|)
value|(0x003009A0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFTXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFTXC_LXOFFTXC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXOFFTXC_LXOFFTXC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_LXOFFTXC_LXOFFTXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONRXC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300140 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONRXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONRXC_LXONRXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONRXC_LXONRXCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_LXONRXC_LXONRXCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONTXC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300980 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONTXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONTXC_LXONTXC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_LXONTXC_LXONTXC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_LXONTXC_LXONTXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MLFC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300020 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_MLFC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MLFC_MLFC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MLFC_MLFC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_MLFC_MLFC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x003005C4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCH_MPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCH_MPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_MPRCH_MPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x003005C0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCL_MPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPRCL_MPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_MPRCL_MPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x003009E4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCH_MPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCH_MPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_MPTCH_MPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x003009E0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCL_MPTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MPTCL_MPTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_MPTCL_MPTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MRFC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300040 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_MRFC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MRFC_MRFC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_MRFC_MRFC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_MRFC_MRFC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300504 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023H_PRC1023H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023H_PRC1023H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PRC1023H_PRC1023H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300500 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023L_PRC1023L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1023L_PRC1023L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PRC1023L_PRC1023L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127H
parameter_list|(
name|_i
parameter_list|)
value|(0x003004A4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127H_PRC127H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127H_PRC127H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PRC127H_PRC127H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127L
parameter_list|(
name|_i
parameter_list|)
value|(0x003004A0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127L_PRC127L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC127L_PRC127L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PRC127L_PRC127L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300524 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522H_PRC1522H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522H_PRC1522H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PRC1522H_PRC1522H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300520 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522L_PRC1522L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC1522L_PRC1522L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PRC1522L_PRC1522L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255H
parameter_list|(
name|_i
parameter_list|)
value|(0x003004C4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255H_PRTPRC255H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255H_PRTPRC255H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PRC255H_PRTPRC255H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255L
parameter_list|(
name|_i
parameter_list|)
value|(0x003004C0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255L_PRC255L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC255L_PRC255L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PRC255L_PRC255L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511H
parameter_list|(
name|_i
parameter_list|)
value|(0x003004E4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511H_PRC511H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511H_PRC511H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PRC511H_PRC511H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511L
parameter_list|(
name|_i
parameter_list|)
value|(0x003004E0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511L_PRC511L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC511L_PRC511L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PRC511L_PRC511L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300484 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64H_PRC64H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64H_PRC64H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PRC64H_PRC64H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300480 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64L_PRC64L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC64L_PRC64L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PRC64L_PRC64L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300544 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522H_PRC1522H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522H_PRC1522H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PRC9522H_PRC1522H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300540 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522L_PRC1522L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PRC9522L_PRC1522L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PRC9522L_PRC1522L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300724 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023H_PTC1023H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023H_PTC1023H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PTC1023H_PTC1023H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300720 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023L_PTC1023L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1023L_PTC1023L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PTC1023L_PTC1023L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127H
parameter_list|(
name|_i
parameter_list|)
value|(0x003006C4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127H_PTC127H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127H_PTC127H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PTC127H_PTC127H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127L
parameter_list|(
name|_i
parameter_list|)
value|(0x003006C0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127L_PTC127L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC127L_PTC127L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PTC127L_PTC127L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300744 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522H_PTC1522H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522H_PTC1522H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PTC1522H_PTC1522H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300740 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522L_PTC1522L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC1522L_PTC1522L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PTC1522L_PTC1522L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255H
parameter_list|(
name|_i
parameter_list|)
value|(0x003006E4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255H_PTC255H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255H_PTC255H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PTC255H_PTC255H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255L
parameter_list|(
name|_i
parameter_list|)
value|(0x003006E0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255L_PTC255L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC255L_PTC255L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PTC255L_PTC255L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300704 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511H_PTC511H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511H_PTC511H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PTC511H_PTC511H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300700 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511L_PTC511L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC511L_PTC511L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PTC511L_PTC511L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64H
parameter_list|(
name|_i
parameter_list|)
value|(0x003006A4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64H_PTC64H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64H_PTC64H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PTC64H_PTC64H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64L
parameter_list|(
name|_i
parameter_list|)
value|(0x003006A0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64L_PTC64L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC64L_PTC64L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PTC64L_PTC64L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522H
parameter_list|(
name|_i
parameter_list|)
value|(0x00300764 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522H_PTC9522H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522H_PTC9522H_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_PTC9522H_PTC9522H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522L
parameter_list|(
name|_i
parameter_list|)
value|(0x00300760 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522L_PTC9522L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PTC9522L_PTC9522L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PTC9522L_PTC9522L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFRXC
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00300280 + ((_i) * 8 + (_j) * 32))
end_define

begin_comment
comment|/* _i=0...3, _j=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFRXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFRXC_PRPXOFFRXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFRXC_PRPXOFFRXCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PXOFFRXC_PRPXOFFRXCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFTXC
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00300880 + ((_i) * 8 + (_j) * 32))
end_define

begin_comment
comment|/* _i=0...3, _j=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFTXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFTXC_PRPXOFFTXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXOFFTXC_PRPXOFFTXCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PXOFFTXC_PRPXOFFTXCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONRXC
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00300180 + ((_i) * 8 + (_j) * 32))
end_define

begin_comment
comment|/* _i=0...3, _j=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONRXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONRXC_PRPXONRXCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONRXC_PRPXONRXCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PXONRXC_PRPXONRXCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONTXC
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00300780 + ((_i) * 8 + (_j) * 32))
end_define

begin_comment
comment|/* _i=0...3, _j=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONTXC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONTXC_PRPXONTXC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_PXONTXC_PRPXONTXC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_PXONTXC_PRPXONTXC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RDPC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300600 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_RDPC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RDPC_RDPC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RDPC_RDPC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_RDPC_RDPC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RFC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300560 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_RFC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RFC_RFC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RFC_RFC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_RFC_RFC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RJC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300580 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_RJC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RJC_RJC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RJC_RJC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_RJC_RJC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RLEC
parameter_list|(
name|_i
parameter_list|)
value|(0x003000A0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_RLEC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RLEC_RLEC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RLEC_RLEC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_RLEC_RLEC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_ROC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300120 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_ROC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_ROC_ROC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_ROC_ROC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_ROC_ROC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RUC
parameter_list|(
name|_i
parameter_list|)
value|(0x00300100 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_RUC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RUC_RUC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RUC_RUC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_RUC_RUC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RUPP
parameter_list|(
name|_i
parameter_list|)
value|(0x00300660 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_RUPP_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RUPP_RUPP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RUPP_RUPP_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_RUPP_RUPP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RXON2OFFCNT
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00300380 + ((_i) * 8 + (_j) * 32))
end_define

begin_comment
comment|/* _i=0...3, _j=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_RXON2OFFCNT_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RXON2OFFCNT_PRRXON2OFFCNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_RXON2OFFCNT_PRRXON2OFFCNT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_RXON2OFFCNT_PRRXON2OFFCNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_TDOLD
parameter_list|(
name|_i
parameter_list|)
value|(0x00300A20 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_TDOLD_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_TDOLD_GLPRT_TDOLD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_TDOLD_GLPRT_TDOLD_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_TDOLD_GLPRT_TDOLD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_TDPC
parameter_list|(
name|_i
parameter_list|)
value|(0x00375400 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_TDPC_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_TDPC_TDPC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_TDPC_TDPC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_TDPC_TDPC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x003005A4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCH_UPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCH_UPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_UPRCH_UPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x003005A0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCL_UPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPRCL_UPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_UPRCL_UPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x003009C4 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCH_UPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCH_UPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLPRT_UPTCH_UPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x003009C0 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCL_VUPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPRT_UPTCL_VUPTCH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLPRT_UPTCL_VUPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00370104 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCH_BPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCH_BPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_BPRCH_BPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00370100 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCL_BPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPRCL_BPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_BPRCL_BPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00340104 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCH_BPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCH_BPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_BPTCH_BPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00340100 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCL_BPTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_BPTCL_BPTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_BPTCL_BPTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GORCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0035C004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_GORCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GORCH_GORCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GORCH_GORCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_GORCH_GORCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GORCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0035c000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_GORCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GORCL_GORCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GORCL_GORCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_GORCL_GORCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0032C004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCH_GOTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCH_GOTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_GOTCH_GOTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0032c000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCL_GOTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_GOTCL_GOTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_GOTCL_GOTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00370084 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCH_MPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCH_MPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_MPRCH_MPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00370080 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCL_MPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPRCL_MPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_MPRCL_MPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00340084 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCH_MPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCH_MPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_MPTCH_MPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00340080 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCL_MPTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_MPTCL_MPTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_MPTCL_MPTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_RUPP
parameter_list|(
name|_i
parameter_list|)
value|(0x00370180 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_RUPP_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_RUPP_RUPP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_RUPP_RUPP_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_RUPP_RUPP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_TDPC
parameter_list|(
name|_i
parameter_list|)
value|(0x00348000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_TDPC_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_TDPC_TDPC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_TDPC_TDPC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_TDPC_TDPC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00370004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCH_UPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCH_UPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_UPRCH_UPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00370000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCL_UPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPRCL_UPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_UPRCL_UPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00340004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCH_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCH_UPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCH_UPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLSW_UPTCH_UPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00340000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCL_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCL_UPTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSW_UPTCL_UPTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLSW_UPTCL_UPTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0036D804 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_BPRCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPRCH_BPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPRCH_BPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_BPRCH_BPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0036d800 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_BPRCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPRCL_BPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPRCL_BPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_BPRCL_BPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0033D804 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_BPTCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPTCH_BPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPTCH_BPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_BPTCH_BPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0033d800 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_BPTCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPTCL_BPTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_BPTCL_BPTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_BPTCL_BPTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GORCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00358004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_GORCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GORCH_GORCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GORCH_GORCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_GORCH_GORCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GORCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00358000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_GORCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GORCL_GORCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GORCL_GORCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_GORCL_GORCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GOTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00328004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_GOTCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GOTCH_GOTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GOTCH_GOTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_GOTCH_GOTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GOTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00328000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_GOTCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GOTCL_GOTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_GOTCL_GOTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_GOTCL_GOTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0036CC04 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_MPRCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPRCH_MPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPRCH_MPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_MPRCH_MPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0036cc00 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_MPRCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPRCL_MPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPRCL_MPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_MPRCL_MPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0033CC04 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_MPTCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPTCH_MPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPTCH_MPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_MPTCH_MPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0033cc00 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_MPTCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPTCL_MPTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_MPTCL_MPTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_MPTCL_MPTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_RDPC
parameter_list|(
name|_i
parameter_list|)
value|(0x00310000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_RDPC_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_RDPC_RDPC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_RDPC_RDPC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_RDPC_RDPC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_RUPP
parameter_list|(
name|_i
parameter_list|)
value|(0x0036E400 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_RUPP_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_RUPP_RUPP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_RUPP_RUPP_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_RUPP_RUPP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_TEPC
parameter_list|(
name|_VSI
parameter_list|)
value|(0x00344000 + ((_VSI) * 4))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_TEPC_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_TEPC_TEPC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_TEPC_TEPC_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_TEPC_TEPC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPRCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0036C004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_UPRCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPRCH_UPRCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPRCH_UPRCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_UPRCH_UPRCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPRCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0036c000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_UPRCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPRCL_UPRCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPRCL_UPRCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_UPRCL_UPRCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x0033C004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_UPTCH_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPTCH_GLVUPTCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPTCH_GLVUPTCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLV_UPTCH_GLVUPTCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x0033c000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...383 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLV_UPTCL_MAX_INDEX
value|383
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPTCL_UPTCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLV_UPTCL_UPTCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLV_UPTCL_UPTCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCH
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00364004 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCH_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCH_TCBCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCH_TCBCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBTC_RBCH_TCBCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCL
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00364000 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCL_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCL_TCBCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RBCL_TCBCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBTC_RBCL_TCBCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCH
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00368004 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCH_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCH_TCPCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCH_TCPCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBTC_RPCH_TCPCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCL
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00368000 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCL_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCL_TCPCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_RPCL_TCPCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBTC_RPCL_TCPCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCH
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00334004 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCH_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCH_TCBCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCH_TCBCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBTC_TBCH_TCBCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCL
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00334000 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCL_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCL_TCBCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TBCL_TCBCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBTC_TBCL_TCBCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCH
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00338004 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCH_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCH_TCPCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCH_TCPCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBTC_TPCH_TCPCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCL
parameter_list|(
name|_i
parameter_list|,
name|_j
parameter_list|)
value|(0x00338000 + ((_i) * 8 + (_j) * 64))
end_define

begin_comment
comment|/* _i=0...7, _j=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCL_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCL_TCPCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBTC_TPCL_TCPCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBTC_TPCL_TCPCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00374804 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCH_VLBPCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCH_VLBPCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBVL_BPCH_VLBPCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00374800 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCL_VLBPCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_BPCL_VLBPCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBVL_BPCL_VLBPCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00360004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCH_VLBCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCH_VLBCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBVL_GORCH_VLBCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00360000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCL_VLBCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GORCL_VLBCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBVL_GORCL_VLBCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00330004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCH_VLBCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCH_VLBCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBVL_GOTCH_VLBCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00330000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCL_VLBCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_GOTCL_VLBCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBVL_GOTCL_VLBCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00374404 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCH_VLMPCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCH_VLMPCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBVL_MPCH_VLMPCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00374400 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCL_VLMPCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_MPCL_VLMPCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBVL_MPCL_VLMPCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCH
parameter_list|(
name|_i
parameter_list|)
value|(0x00374004 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCH_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCH_VLUPCH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCH_VLUPCH_MASK
value|I40E_MASK(0xFFFF, I40E_GLVEBVL_UPCH_VLUPCH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCL
parameter_list|(
name|_i
parameter_list|)
value|(0x00374000 + ((_i) * 8))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCL_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCL_VLUPCL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLVEBVL_UPCL_VLUPCL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GLVEBVL_UPCL_VLUPCL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MTG_FLU_MSK_H
value|0x00269F4C
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_MTG_FLU_MSK_H_MASK_HIGH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_MTG_FLU_MSK_H_MASK_HIGH_MASK
value|I40E_MASK(0xFFFF, I40E_GL_MTG_FLU_MSK_H_MASK_HIGH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT
parameter_list|(
name|_i
parameter_list|)
value|(0x00270200 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...35 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT_MAX_INDEX
value|35
end_define

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT_DEF_ACTION_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT_DEF_ACTION_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_SWR_DEF_ACT_DEF_ACTION_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT_EN
parameter_list|(
name|_i
parameter_list|)
value|(0x0026CFB8 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT_EN_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT_EN_DEF_ACT_EN_BITMAP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_SWR_DEF_ACT_EN_DEF_ACT_EN_BITMAP_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_GL_SWR_DEF_ACT_EN_DEF_ACT_EN_BITMAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_ADJ
value|0x001E4280
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_ADJ_TSYNADJ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_ADJ_TSYNADJ_MASK
value|I40E_MASK(0x7FFFFFFF, I40E_PRTTSYN_ADJ_TSYNADJ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_ADJ_SIGN_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_ADJ_SIGN_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_ADJ_SIGN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0
parameter_list|(
name|_i
parameter_list|)
value|(0x001E42A0 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_OUT_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_OUT_ENA_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_AUX_0_OUT_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_OUTMOD_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_OUTMOD_MASK
value|I40E_MASK(0x3, I40E_PRTTSYN_AUX_0_OUTMOD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_OUTLVL_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_OUTLVL_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_AUX_0_OUTLVL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_PULSEW_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_PULSEW_MASK
value|I40E_MASK(0xF, I40E_PRTTSYN_AUX_0_PULSEW_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_EVNTLVL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_0_EVNTLVL_MASK
value|I40E_MASK(0x3, I40E_PRTTSYN_AUX_0_EVNTLVL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_1
parameter_list|(
name|_i
parameter_list|)
value|(0x001E42E0 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_1_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_1_INSTNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_1_INSTNT_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_AUX_1_INSTNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_1_SAMPLE_TIME_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_AUX_1_SAMPLE_TIME_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_AUX_1_SAMPLE_TIME_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CLKO
parameter_list|(
name|_i
parameter_list|)
value|(0x001E4240 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CLKO_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CLKO_TSYNCLKO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CLKO_TSYNCLKO_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_CLKO_TSYNCLKO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0
value|0x001E4200
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_CLEAR_TSYNTIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_CLEAR_TSYNTIMER_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_CTL0_CLEAR_TSYNTIMER_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TXTIME_INT_ENA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TXTIME_INT_ENA_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_CTL0_TXTIME_INT_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_EVENT_INT_ENA_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_EVENT_INT_ENA_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_CTL0_EVENT_INT_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TGT_INT_ENA_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TGT_INT_ENA_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_CTL0_TGT_INT_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_PF_ID_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_PF_ID_MASK
value|I40E_MASK(0xF, I40E_PRTTSYN_CTL0_PF_ID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TSYNACT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TSYNACT_MASK
value|I40E_MASK(0x3, I40E_PRTTSYN_CTL0_TSYNACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TSYNENA_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL0_TSYNENA_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_CTL0_TSYNENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1
value|0x00085020
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V1MESSTYPE0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V1MESSTYPE0_MASK
value|I40E_MASK(0xFF, I40E_PRTTSYN_CTL1_V1MESSTYPE0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V1MESSTYPE1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V1MESSTYPE1_MASK
value|I40E_MASK(0xFF, I40E_PRTTSYN_CTL1_V1MESSTYPE1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V2MESSTYPE0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V2MESSTYPE0_MASK
value|I40E_MASK(0xF, I40E_PRTTSYN_CTL1_V2MESSTYPE0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V2MESSTYPE1_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_V2MESSTYPE1_MASK
value|I40E_MASK(0xF, I40E_PRTTSYN_CTL1_V2MESSTYPE1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_TSYNTYPE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_TSYNTYPE_MASK
value|I40E_MASK(0x3, I40E_PRTTSYN_CTL1_TSYNTYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_UDP_ENA_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_UDP_ENA_MASK
value|I40E_MASK(0x3, I40E_PRTTSYN_CTL1_UDP_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_TSYNENA_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_CTL1_TSYNENA_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_CTL1_TSYNENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_H
parameter_list|(
name|_i
parameter_list|)
value|(0x001E40C0 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_H_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_H_TSYNEVNT_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_H_TSYNEVNT_H_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_EVNT_H_TSYNEVNT_H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_L
parameter_list|(
name|_i
parameter_list|)
value|(0x001E4080 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_L_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_L_TSYNEVNT_L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_EVNT_L_TSYNEVNT_L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_EVNT_L_TSYNEVNT_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_INC_H
value|0x001E4060
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_INC_H_TSYNINC_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_INC_H_TSYNINC_H_MASK
value|I40E_MASK(0x3F, I40E_PRTTSYN_INC_H_TSYNINC_H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_INC_L
value|0x001E4040
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_INC_L_TSYNINC_L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_INC_L_TSYNINC_L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_INC_L_TSYNINC_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_H
parameter_list|(
name|_i
parameter_list|)
value|(0x00085040 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_H_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_H_RXTIEM_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_H_RXTIEM_H_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_RXTIME_H_RXTIEM_H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_L
parameter_list|(
name|_i
parameter_list|)
value|(0x000850C0 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_L_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_L_RXTIEM_L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_RXTIME_L_RXTIEM_L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_RXTIME_L_RXTIEM_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0
value|0x001E4220
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_EVENT0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_EVENT0_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_0_EVENT0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_EVENT1_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_EVENT1_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_0_EVENT1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_TGT0_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_TGT0_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_0_TGT0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_TGT1_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_TGT1_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_0_TGT1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_TXTIME_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_0_TXTIME_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_0_TXTIME_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1
value|0x00085140
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT0_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_1_RXT0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT1_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT1_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_1_RXT1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT2_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT2_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_1_RXT2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT3_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_STAT_1_RXT3_MASK
value|I40E_MASK(0x1, I40E_PRTTSYN_STAT_1_RXT3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_H
parameter_list|(
name|_i
parameter_list|)
value|(0x001E4180 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_H_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_H_TSYNTGTT_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_H_TSYNTGTT_H_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_TGT_H_TSYNTGTT_H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_L
parameter_list|(
name|_i
parameter_list|)
value|(0x001E4140 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_L_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_L_TSYNTGTT_L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TGT_L_TSYNTGTT_L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_TGT_L_TSYNTGTT_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TIME_H
value|0x001E4120
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TIME_H_TSYNTIME_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TIME_H_TSYNTIME_H_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_TIME_H_TSYNTIME_H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TIME_L
value|0x001E4100
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TIME_L_TSYNTIME_L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TIME_L_TSYNTIME_L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_TIME_L_TSYNTIME_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TXTIME_H
value|0x001E41E0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TXTIME_H_TXTIEM_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TXTIME_H_TXTIEM_H_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_TXTIME_H_TXTIEM_H_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TXTIME_L
value|0x001E41C0
end_define

begin_comment
comment|/* Reset: GLOBR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TXTIME_L_TXTIEM_L_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTTSYN_TXTIME_L_TXTIEM_L_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTTSYN_TXTIME_L_TXTIEM_L_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLSCD_QUANTA
value|0x000B2080
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GLSCD_QUANTA_TSCDQUANTA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLSCD_QUANTA_TSCDQUANTA_MASK
value|I40E_MASK(0x7, I40E_GLSCD_QUANTA_TSCDQUANTA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX
value|0x0012A510
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_FUNCTION_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_FUNCTION_MASK
value|I40E_MASK(0xFF, I40E_GL_MDET_RX_FUNCTION_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_EVENT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_EVENT_MASK
value|I40E_MASK(0x1FF, I40E_GL_MDET_RX_EVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_QUEUE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_QUEUE_MASK
value|I40E_MASK(0x3FFF, I40E_GL_MDET_RX_QUEUE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_VALID_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_RX_VALID_MASK
value|I40E_MASK(0x1, I40E_GL_MDET_RX_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX
value|0x000E6480
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_QUEUE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_QUEUE_MASK
value|I40E_MASK(0xFFF, I40E_GL_MDET_TX_QUEUE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_VF_NUM_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_VF_NUM_MASK
value|I40E_MASK(0x1FF, I40E_GL_MDET_TX_VF_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_PF_NUM_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_PF_NUM_MASK
value|I40E_MASK(0xF, I40E_GL_MDET_TX_PF_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_EVENT_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_EVENT_MASK
value|I40E_MASK(0x1F, I40E_GL_MDET_TX_EVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_VALID_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_GL_MDET_TX_VALID_MASK
value|I40E_MASK(0x1, I40E_GL_MDET_TX_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_MDET_RX
value|0x0012A400
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_MDET_RX_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_MDET_RX_VALID_MASK
value|I40E_MASK(0x1, I40E_PF_MDET_RX_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_MDET_TX
value|0x000E6400
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_MDET_TX_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_MDET_TX_VALID_MASK
value|I40E_MASK(0x1, I40E_PF_MDET_TX_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_VT_PFALLOC
value|0x001C0500
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_PF_VT_PFALLOC_FIRSTVF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PF_VT_PFALLOC_FIRSTVF_MASK
value|I40E_MASK(0xFF, I40E_PF_VT_PFALLOC_FIRSTVF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_VT_PFALLOC_LASTVF_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PF_VT_PFALLOC_LASTVF_MASK
value|I40E_MASK(0xFF, I40E_PF_VT_PFALLOC_LASTVF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PF_VT_PFALLOC_VALID_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PF_VT_PFALLOC_VALID_MASK
value|I40E_MASK(0x1, I40E_PF_VT_PFALLOC_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VP_MDET_RX
parameter_list|(
name|_VF
parameter_list|)
value|(0x0012A000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VP_MDET_RX_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VP_MDET_RX_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VP_MDET_RX_VALID_MASK
value|I40E_MASK(0x1, I40E_VP_MDET_RX_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VP_MDET_TX
parameter_list|(
name|_VF
parameter_list|)
value|(0x000E6000 + ((_VF) * 4))
end_define

begin_comment
comment|/* _i=0...127 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VP_MDET_TX_MAX_INDEX
value|127
end_define

begin_define
define|#
directive|define
name|I40E_VP_MDET_TX_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VP_MDET_TX_VALID_MASK
value|I40E_MASK(0x1, I40E_VP_MDET_TX_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC
value|0x0006C800
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_NOTCO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_NOTCO_MASK
value|I40E_MASK(0x1, I40E_GLPM_WUMC_NOTCO_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_SRST_PIN_VAL_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_SRST_PIN_VAL_MASK
value|I40E_MASK(0x1, I40E_GLPM_WUMC_SRST_PIN_VAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_ROL_MODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_ROL_MODE_MASK
value|I40E_MASK(0x1, I40E_GLPM_WUMC_ROL_MODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_RESERVED_4_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_RESERVED_4_MASK
value|I40E_MASK(0x1FFF, I40E_GLPM_WUMC_RESERVED_4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_MNG_WU_PF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_GLPM_WUMC_MNG_WU_PF_MASK
value|I40E_MASK(0xFFFF, I40E_GLPM_WUMC_MNG_WU_PF_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_APM
value|0x000B8080
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPM_APM_APME_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_APM_APME_MASK
value|I40E_MASK(0x1, I40E_PFPM_APM_APME_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_FHFT_LENGTH
parameter_list|(
name|_i
parameter_list|)
value|(0x0006A000 + ((_i) * 128))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPM_FHFT_LENGTH_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_FHFT_LENGTH_LENGTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_FHFT_LENGTH_LENGTH_MASK
value|I40E_MASK(0xFF, I40E_PFPM_FHFT_LENGTH_LENGTH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUC
value|0x0006B200
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPM_WUC_EN_APM_D0_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUC_EN_APM_D0_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUC_EN_APM_D0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC
value|0x0006B400
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_LNKC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_LNKC_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_LNKC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_MAG_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_MAG_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_MAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_MNG_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_MNG_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_MNG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX0_ACT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX0_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX0_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX1_ACT_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX1_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX1_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX2_ACT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX2_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX2_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX3_ACT_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX3_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX3_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX4_ACT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX4_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX4_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX5_ACT_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX5_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX5_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX6_ACT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX6_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX6_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX7_ACT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX7_ACT_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX7_ACT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX0_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX1_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX1_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX2_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX2_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX3_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX3_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX4_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX4_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX5_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX5_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX6_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX6_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX7_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FLX7_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FLX7_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FW_RST_WK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUFC_FW_RST_WK_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUFC_FW_RST_WK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS
value|0x0006B600
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_LNKC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_LNKC_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_LNKC_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_MAG_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_MAG_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_MAG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_PME_STATUS_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_PME_STATUS_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_PME_STATUS_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_MNG_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_MNG_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_MNG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX0_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX1_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX1_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX2_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX2_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX3_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX3_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX4_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX4_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX5_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX5_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX6_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX6_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX7_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FLX7_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FLX7_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FW_RST_WK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PFPM_WUS_FW_RST_WK_MASK
value|I40E_MASK(0x1, I40E_PFPM_WUS_FW_RST_WK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_FHFHR
value|0x0006C000
end_define

begin_comment
comment|/* Reset: POR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_FHFHR_UNICAST_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_FHFHR_UNICAST_MASK
value|I40E_MASK(0x1, I40E_PRTPM_FHFHR_UNICAST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_FHFHR_MULTICAST_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_FHFHR_MULTICAST_MASK
value|I40E_MASK(0x1, I40E_PRTPM_FHFHR_MULTICAST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH
parameter_list|(
name|_i
parameter_list|)
value|(0x001E44C0 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_PFPM_SAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_PFPM_SAH_MASK
value|I40E_MASK(0xFFFF, I40E_PRTPM_SAH_PFPM_SAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_PF_NUM_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_PF_NUM_MASK
value|I40E_MASK(0xF, I40E_PRTPM_SAH_PF_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_MC_MAG_EN_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_MC_MAG_EN_MASK
value|I40E_MASK(0x1, I40E_PRTPM_SAH_MC_MAG_EN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_AV_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAH_AV_MASK
value|I40E_MASK(0x1, I40E_PRTPM_SAH_AV_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAL
parameter_list|(
name|_i
parameter_list|)
value|(0x001E4440 + ((_i) * 32))
end_define

begin_comment
comment|/* _i=0...3 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_PRTPM_SAL_MAX_INDEX
value|3
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAL_PFPM_SAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_PRTPM_SAL_PFPM_SAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_PRTPM_SAL_PFPM_SAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAH1
value|0x00006000
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQBAH1_ARQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAH1_ARQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ARQBAH1_ARQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAL1
value|0x00006C00
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQBAL1_ARQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQBAL1_ARQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ARQBAL1_ARQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQH1
value|0x00007400
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQH1_ARQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQH1_ARQH_MASK
value|I40E_MASK(0x3FF, I40E_VF_ARQH1_ARQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1
value|0x00008000
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQLEN_MASK
value|I40E_MASK(0x3FF, I40E_VF_ARQLEN1_ARQLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQVFE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQVFE_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQVFE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQOVFL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQOVFL_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQOVFL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQCRIT_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQCRIT_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQCRIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQENABLE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQLEN1_ARQENABLE_MASK
value|I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQT1
value|0x00007000
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ARQT1_ARQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ARQT1_ARQT_MASK
value|I40E_MASK(0x3FF, I40E_VF_ARQT1_ARQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAH1
value|0x00007800
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQBAH1_ATQBAH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAH1_ATQBAH_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ATQBAH1_ATQBAH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAL1
value|0x00007C00
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQBAL1_ATQBAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQBAL1_ATQBAL_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VF_ATQBAL1_ATQBAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQH1
value|0x00006400
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQH1_ATQH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQH1_ATQH_MASK
value|I40E_MASK(0x3FF, I40E_VF_ATQH1_ATQH_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1
value|0x00006800
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQLEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQLEN_MASK
value|I40E_MASK(0x3FF, I40E_VF_ATQLEN1_ATQLEN_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQVFE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQVFE_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQVFE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQOVFL_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQOVFL_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQOVFL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQCRIT_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQCRIT_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQCRIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQENABLE_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQLEN1_ATQENABLE_MASK
value|I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQENABLE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQT1
value|0x00008400
end_define

begin_comment
comment|/* Reset: EMPR */
end_comment

begin_define
define|#
directive|define
name|I40E_VF_ATQT1_ATQT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VF_ATQT1_ATQT_MASK
value|I40E_MASK(0x3FF, I40E_VF_ATQT1_ATQT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFGEN_RSTAT
value|0x00008800
end_define

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFGEN_RSTAT_VFR_STATE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFGEN_RSTAT_VFR_STATE_MASK
value|I40E_MASK(0x3, I40E_VFGEN_RSTAT_VFR_STATE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01
value|0x00005C00
end_define

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_INTENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_INTENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_INTENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_CLEARPBA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_CLEARPBA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_CLEARPBA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_SWINT_TRIG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_SWINT_TRIG_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_SWINT_TRIG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_ITR_INDX_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTL01_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_INTERVAL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_DYN_CTL01_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_SW_ITR_INDX_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_SW_ITR_INDX_ENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_SW_ITR_INDX_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_SW_ITR_INDX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_SW_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTL01_SW_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_INTENA_MSK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTL01_INTENA_MSK_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_INTENA_MSK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1
parameter_list|(
name|_INTVF
parameter_list|)
value|(0x00003800 + ((_INTVF) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_INTENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_INTENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_INTENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_CLEARPBA_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_CLEARPBA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_CLEARPBA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_SWINT_TRIG_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_SWINT_TRIG_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_SWINT_TRIG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_ITR_INDX_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTLN1_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_INTERVAL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_DYN_CTLN1_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_ENA_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_ENA_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_INTENA_MSK_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_DYN_CTLN1_INTENA_MSK_MASK
value|I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_INTENA_MSK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA1
value|0x00005000
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA1_LINK_STAT_CHANGE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA1_LINK_STAT_CHANGE_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_ENA1_LINK_STAT_CHANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA1_ADMINQ_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA1_ADMINQ_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_ENA1_ADMINQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA1_RSVD_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR0_ENA1_RSVD_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR0_ENA1_RSVD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01
value|0x00004800
end_define

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_INTEVENT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_INTEVENT_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_INTEVENT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_0_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_0_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_1_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_1_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_2_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_2_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_3_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_QUEUE_3_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_LINK_STAT_CHANGE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_LINK_STAT_CHANGE_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_LINK_STAT_CHANGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_ADMINQ_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_ADMINQ_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_ADMINQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_SWINT_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ICR01_SWINT_MASK
value|I40E_MASK(0x1, I40E_VFINT_ICR01_SWINT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITR01
parameter_list|(
name|_i
parameter_list|)
value|(0x00004C00 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...2 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ITR01_MAX_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITR01_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITR01_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_ITR01_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN1
parameter_list|(
name|_i
parameter_list|,
name|_INTVF
parameter_list|)
value|(0x00002800 + ((_i) * 64 + (_INTVF) * 4))
end_define

begin_comment
comment|/* _i=0...2, _INTVF=0...15 */
end_comment

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN1_MAX_INDEX
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN1_INTERVAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_ITRN1_INTERVAL_MASK
value|I40E_MASK(0xFFF, I40E_VFINT_ITRN1_INTERVAL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_STAT_CTL01
value|0x00005400
end_define

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFINT_STAT_CTL01_OTHER_ITR_INDX_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFINT_STAT_CTL01_OTHER_ITR_INDX_MASK
value|I40E_MASK(0x3, I40E_VFINT_STAT_CTL01_OTHER_ITR_INDX_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QRX_TAIL1
parameter_list|(
name|_Q
parameter_list|)
value|(0x00002000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_QRX_TAIL1_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_QRX_TAIL1_TAIL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QRX_TAIL1_TAIL_MASK
value|I40E_MASK(0x1FFF, I40E_QRX_TAIL1_TAIL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_QTX_TAIL1
parameter_list|(
name|_Q
parameter_list|)
value|(0x00000000 + ((_Q) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: PFR */
end_comment

begin_define
define|#
directive|define
name|I40E_QTX_TAIL1_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_QTX_TAIL1_TAIL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_QTX_TAIL1_TAIL_MASK
value|I40E_MASK(0x1FFF, I40E_QTX_TAIL1_TAIL_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_PBA
value|0x00002000
end_define

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_PBA_PENBIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_PBA_PENBIT_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_PBA_PENBIT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD
parameter_list|(
name|_i
parameter_list|)
value|(0x00000000 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...16 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD_MAX_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD_MSIXTADD10_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD_MSIXTADD10_MASK
value|I40E_MASK(0x3, I40E_VFMSIX_TADD_MSIXTADD10_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD_MSIXTADD_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TADD_MSIXTADD_MASK
value|I40E_MASK(0x3FFFFFFF, I40E_VFMSIX_TADD_MSIXTADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG
parameter_list|(
name|_i
parameter_list|)
value|(0x00000008 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...16 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG_MAX_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG_MSIXTMSG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TMSG_MSIXTMSG_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TMSG_MSIXTMSG_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD
parameter_list|(
name|_i
parameter_list|)
value|(0x00000004 + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...16 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD_MAX_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD_MSIXTUADD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TUADD_MSIXTUADD_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TUADD_MSIXTUADD_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL
parameter_list|(
name|_i
parameter_list|)
value|(0x0000000C + ((_i) * 16))
end_define

begin_comment
comment|/* _i=0...16 */
end_comment

begin_comment
comment|/* Reset: VFLR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL_MAX_INDEX
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL_MASK_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFMSIX_TVCTRL_MASK_MASK
value|I40E_MASK(0x1, I40E_VFMSIX_TVCTRL_MASK_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA
value|0x0000DC00
end_define

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA_ERROR_CODE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA_ERROR_CODE_MASK
value|I40E_MASK(0xF, I40E_VFCM_PE_ERRDATA_ERROR_CODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA_Q_TYPE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA_Q_TYPE_MASK
value|I40E_MASK(0x7, I40E_VFCM_PE_ERRDATA_Q_TYPE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA_Q_NUM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRDATA_Q_NUM_MASK
value|I40E_MASK(0x3FFFF, I40E_VFCM_PE_ERRDATA_Q_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO
value|0x0000D800
end_define

begin_comment
comment|/* Reset: VFR */
end_comment

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_ERROR_VALID_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_ERROR_VALID_MASK
value|I40E_MASK(0x1, I40E_VFCM_PE_ERRINFO_ERROR_VALID_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_ERROR_INST_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_ERROR_INST_MASK
value|I40E_MASK(0x7, I40E_VFCM_PE_ERRINFO_ERROR_INST_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_DBL_ERROR_CNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_DBL_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO_DBL_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_RLU_ERROR_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_RLU_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO_RLU_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_RLS_ERROR_CNT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFCM_PE_ERRINFO_RLS_ERROR_CNT_MASK
value|I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO_RLS_ERROR_CNT_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HENA
parameter_list|(
name|_i
parameter_list|)
value|(0x0000C400 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...1 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HENA_MAX_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HENA_PTYPE_ENA_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HENA_PTYPE_ENA_MASK
value|I40E_MASK(0xFFFFFFFF, I40E_VFQF_HENA_PTYPE_ENA_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY
parameter_list|(
name|_i
parameter_list|)
value|(0x0000CC00 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...12 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_MAX_INDEX
value|12
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_0_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_1_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_2_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HKEY_KEY_3_MASK
value|I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT
parameter_list|(
name|_i
parameter_list|)
value|(0x0000D000 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...15 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_MAX_INDEX
value|15
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT0_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT_LUT0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT1_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT_LUT1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT2_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT_LUT2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HLUT_LUT3_MASK
value|I40E_MASK(0xF, I40E_VFQF_HLUT_LUT3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION
parameter_list|(
name|_i
parameter_list|)
value|(0x0000D400 + ((_i) * 4))
end_define

begin_comment
comment|/* _i=0...7 */
end_comment

begin_comment
comment|/* Reset: CORER */
end_comment

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_MAX_INDEX
value|7
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_0_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_0_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_0_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_0_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_1_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_1_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_1_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_1_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_2_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_2_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_2_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_2_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_3_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_3_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_3_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_3_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_4_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_4_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_4_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_4_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_4_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_5_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_5_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_5_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_5_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_5_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_6_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_6_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_6_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_6_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_6_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_7_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_OVERRIDE_ENA_7_MASK
value|I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_7_SHIFT)
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_7_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|I40E_VFQF_HREGION_REGION_7_MASK
value|I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_7_SHIFT)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

