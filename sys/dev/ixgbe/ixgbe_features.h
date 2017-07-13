begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation   All rights reserved.    Redistribution and use in source and binary forms, with or without   modification, are permitted provided that the following conditions are met:     1. Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.     2. Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.     3. Neither the name of the Intel Corporation nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_FEATURES_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_FEATURES_H_
end_define

begin_comment
comment|/*  * Feature defines.  Eventually, we'd like to get to a point where we  * can remove MAC/Phy type checks scattered throughout the code in  * favor of checking these feature flags. If the feature expects OS  * support, make sure to add an #undef below if expected to run on  * OSs that don't support said feature.  */
end_comment

begin_define
define|#
directive|define
name|IXGBE_FEATURE_VF
value|(u32)(1<< 0)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_SRIOV
value|(u32)(1<< 1)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_RSS
value|(u32)(1<< 2)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_NETMAP
value|(u32)(1<< 3)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_FAN_FAIL
value|(u32)(1<< 4)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_TEMP_SENSOR
value|(u32)(1<< 5)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_BYPASS
value|(u32)(1<< 6)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_LEGACY_TX
value|(u32)(1<< 7)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_FDIR
value|(u32)(1<< 8)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_MSI
value|(u32)(1<< 9)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_MSIX
value|(u32)(1<< 10)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_EEE
value|(u32)(1<< 11)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_LEGACY_IRQ
value|(u32)(1<< 12)
end_define

begin_define
define|#
directive|define
name|IXGBE_FEATURE_NEEDS_CTXD
value|(u32)(1<< 13)
end_define

begin_comment
comment|/* Check for OS support.  Undefine features if not included in the OS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_IOV
end_ifndef

begin_undef
undef|#
directive|undef
name|IXGBE_FEATURE_SRIOV
end_undef

begin_define
define|#
directive|define
name|IXGBE_FEATURE_SRIOV
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RSS
end_ifndef

begin_undef
undef|#
directive|undef
name|IXGBE_FEATURE_RSS
end_undef

begin_define
define|#
directive|define
name|IXGBE_FEATURE_RSS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_NETMAP
end_ifndef

begin_undef
undef|#
directive|undef
name|IXGBE_FEATURE_NETMAP
end_undef

begin_define
define|#
directive|define
name|IXGBE_FEATURE_NETMAP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_FEATURES_H_ */
end_comment

end_unit

