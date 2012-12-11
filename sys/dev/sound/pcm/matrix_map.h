begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Ariff Abdullah<ariff@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SND_MATRIX_MAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_SND_MATRIX_MAP_H_
end_define

begin_comment
comment|/*  * Standard matrix maps:  *  * struct pcmchan_matrix {  * 	.id = Matrix identity (see matrix.h). Custom defined should use  * 	      one of SND_CHN_MATRIX_MISC (for whatever purposes) or  * 	      SND_CHN_MATRIX_DRV (hardware driver).  * 	.channels = Total number of channels, including whatever 'extended'  * 		    (the X.ext notions, mostly LFE).  * 	.ext = Total number of extended channels (LFE).  * 	.map = {  * 		Sequences of channel type and interleave structure.  * 		[interleave offset] = {  * 			.type = channel type (see matrix.h).  * 			.members = Masks of channels that is acceptable as a  * 				   member of this channel type.  * 		},  * 		[total channels] = {  * 			.type = Maximum channels marker (SND_CHN_T_MAX).  * 			.members = 0 (no channels allowed here).  * 		},  * 	},  * 	.mask = Mask of channels that exist in this map.  * 	.offset = {  * 		channel offset that directly translate to the above interleave  * 		offset according to SND_CHN_T_* definitions.  * 	}  * };  *  * Rule of thumb: Avoid using SND_CHN_T_* that is marked with XXX (matrix.h),  *                or be prepared for the horror to come.  *  */
end_comment

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_1_0
value|{					\ 	.id = SND_CHN_MATRIX_1_0,					\ 	.channels = 1,							\ 	.ext = 0,							\ 	.map = {							\
comment|/* Mono, center, etc. */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |	\ 			    SND_CHN_T_MASK_FC | SND_CHN_T_MASK_LF |	\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |	\ 			    SND_CHN_T_MASK_BC | SND_CHN_T_MASK_SL |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\ 		[1] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_FC,					\ 	.offset = {  0,  0,  0,  0,  0,  0, -1, -1,  0,			\ 		     0,  0, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_2_0
value|{					\ 	.id = SND_CHN_MATRIX_2_0,					\ 	.channels = 2,							\ 	.ext = 0,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BL |	\ 			    SND_CHN_T_MASK_BC | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BR |	\ 			    SND_CHN_T_MASK_BC | SND_CHN_T_MASK_SR	\ 		},							\ 		[2] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR,			\ 	.offset = {  0,  1, -1, -1, -1, -1, -1, -1, -1,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_2_1
value|{					\ 	.id = SND_CHN_MATRIX_2_1,					\ 	.channels = 3,							\ 	.ext = 1,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* LFE */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_LF,				\ 			.members = SND_CHN_T_MASK_LF			\ 		},							\ 		[3] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_LF,					\ 	.offset = {  0,  1, -1,  2, -1, -1, -1, -1, -1,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_3_0
value|{
comment|/* 3 channels default */
value|\ 	.id = SND_CHN_MATRIX_3_0,					\ 	.channels = 3,							\ 	.ext = 0,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_SR	\ 		},							\
comment|/* Rear Center */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BC,				\ 			.members =					\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BL |	\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_SL | SND_CHN_T_MASK_SR	\ 		},							\ 		[3] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BC,					\ 	.offset = {  0,  1, -1, -1, -1, -1, -1, -1,  2,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_3_1
value|{					\ 	.id = SND_CHN_MATRIX_3_1,					\ 	.channels = 4,							\ 	.ext = 1,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* LFE */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_LF,				\ 			.members = SND_CHN_T_MASK_LF			\ 		},							\
comment|/* Rear Center */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BC,				\ 			.members =					\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |	\ 			    SND_CHN_T_MASK_BC |				\ 			    SND_CHN_T_MASK_SL | SND_CHN_T_MASK_SR	\ 		},							\ 		[4] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BC,			\ 	.offset = {  0,  1, -1,  2, -1, -1, -1, -1,  3,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_4_0
value|{					\ 	.id = SND_CHN_MATRIX_4_0,					\ 	.channels = 4,							\ 	.ext = 0,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_SR	\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BL |	\ 			    SND_CHN_T_MASK_BC | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BR |	\ 			    SND_CHN_T_MASK_BC | SND_CHN_T_MASK_SR	\ 		},							\ 		[4] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR,			\ 	.offset = {  0,  1, -1, -1,  2,  3, -1, -1, -1,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_4_1
value|{					\ 	.id = SND_CHN_MATRIX_4_1,					\ 	.channels = 5,							\ 	.ext = 1,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_FC |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* LFE */
value|\ 		[4] = {							\ 			.type = SND_CHN_T_LF,				\ 			.members = SND_CHN_T_MASK_LF			\ 		},							\ 		[5] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |			\ 		SND_CHN_T_MASK_LF,					\ 	.offset = {  0,  1, -1,  4,  2,  3, -1, -1, -1,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_5_0
value|{
comment|/* 5 channels default */
value|\ 	.id = SND_CHN_MATRIX_5_0,					\ 	.channels = 5,							\ 	.ext = 0,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_LF |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_LF |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BL |	\ 			    SND_CHN_T_MASK_BC | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_LF | SND_CHN_T_MASK_BR |	\ 			    SND_CHN_T_MASK_BC | SND_CHN_T_MASK_SR	\ 		},							\
comment|/* Center */
value|\ 		[4] = {							\ 			.type = SND_CHN_T_FC,				\ 			.members = SND_CHN_T_MASK_FC			\ 		},							\ 		[5] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |			\ 		SND_CHN_T_MASK_FC,					\ 	.offset = {  0,  1,  4, -1,  2,  3, -1, -1, -1,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_5_1
value|{
comment|/* 6 channels default */
value|\ 	.id = SND_CHN_MATRIX_5_1,					\ 	.channels = 6,							\ 	.ext = 1,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_SR	\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* Center */
value|\ 		[4] = {							\ 			.type = SND_CHN_T_FC,				\ 			.members = SND_CHN_T_MASK_FC			\ 		},							\
comment|/* LFE */
value|\ 		[5] = {							\ 			.type = SND_CHN_T_LF,				\ 			.members = SND_CHN_T_MASK_LF			\ 		},							\ 		[6] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |			\ 		SND_CHN_T_MASK_FC | SND_CHN_T_MASK_LF,			\ 	.offset = {  0,  1,  4,  5,  2,  3, -1, -1, -1,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_6_0
value|{					\ 	.id = SND_CHN_MATRIX_6_0,					\ 	.channels = 6,							\ 	.ext = 0,							\ 	.map  = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_LF |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_LF |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_LF |	\ 			    SND_CHN_T_MASK_SL				\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_LF |	\ 			    SND_CHN_T_MASK_SR				\ 		},							\
comment|/* Center */
value|\ 		[4] = {							\ 			.type = SND_CHN_T_FC,				\ 			.members = SND_CHN_T_MASK_FC			\ 		},							\
comment|/* Rear Center */
value|\ 		[5] = {							\ 			.type = SND_CHN_T_BC,				\ 			.members = SND_CHN_T_MASK_BC			\ 		},							\ 		[6] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |			\ 		SND_CHN_T_MASK_FC | SND_CHN_T_MASK_BC,			\ 	.offset = {  0,  1,  4, -1,  2,  3, -1, -1,  5,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_6_1
value|{					\ 	.id = SND_CHN_MATRIX_6_1,					\ 	.channels = 7,							\ 	.ext = 1,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_SR	\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_SL	\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_SR	\ 		},							\
comment|/* Center */
value|\ 		[4] = {							\ 			.type = SND_CHN_T_FC,				\ 			.members = SND_CHN_T_MASK_FC			\ 		},							\
comment|/* LFE */
value|\ 		[5] = {							\ 			.type = SND_CHN_T_LF,				\ 			.members = SND_CHN_T_MASK_LF			\ 		},							\
comment|/* Rear Center */
value|\ 		[6] = {							\ 			.type = SND_CHN_T_BC,				\ 			.members = SND_CHN_T_MASK_BC			\ 		},							\ 		[7] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |			\ 		SND_CHN_T_MASK_FC | SND_CHN_T_MASK_LF |			\ 		SND_CHN_T_MASK_BC,					\ 	.offset = {  0,  1,  4,  5,  2,  3, -1, -1,  6,			\ 		    -1, -1, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_7_0
value|{					\ 	.id = SND_CHN_MATRIX_7_0,					\ 	.channels = 7,							\ 	.ext = 0,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members =					\ 			    SND_CHN_T_MASK_FL | SND_CHN_T_MASK_LF	\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members =					\ 			    SND_CHN_T_MASK_FR | SND_CHN_T_MASK_LF	\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_LF				\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_BC |	\ 			    SND_CHN_T_MASK_LF				\ 		},							\
comment|/* Center */
value|\ 		[4] = {							\ 			.type = SND_CHN_T_FC,				\ 			.members =					\ 			    SND_CHN_T_MASK_FC | SND_CHN_T_MASK_LF	\ 		},							\
comment|/* Side Left */
value|\ 		[5] = {							\ 			.type = SND_CHN_T_SL,				\ 			.members =					\ 			    SND_CHN_T_MASK_SL | SND_CHN_T_MASK_LF	\ 		},							\
comment|/* Side Right */
value|\ 		[6] = {							\ 			.type = SND_CHN_T_SR,				\ 			.members =					\ 			    SND_CHN_T_MASK_SR | SND_CHN_T_MASK_LF	\ 		},							\ 		[7] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |			\ 		SND_CHN_T_MASK_FC |					\ 		SND_CHN_T_MASK_SL | SND_CHN_T_MASK_SR,			\ 	.offset = {  0,  1,  4, -1,  2,  3, -1, -1, -1,			\ 		     5,  6, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_define
define|#
directive|define
name|SND_CHN_MATRIX_MAP_7_1
value|{					\ 	.id = SND_CHN_MATRIX_7_1,					\ 	.channels = 8,							\ 	.ext = 1,							\ 	.map = {							\
comment|/* Left */
value|\ 		[0] = {							\ 			.type = SND_CHN_T_FL,				\ 			.members = SND_CHN_T_MASK_FL			\ 		},							\
comment|/* Right */
value|\ 		[1] = {							\ 			.type = SND_CHN_T_FR,				\ 			.members = SND_CHN_T_MASK_FR			\ 		},							\
comment|/* Rear Left */
value|\ 		[2] = {							\ 			.type = SND_CHN_T_BL,				\ 			.members =					\ 			    SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BC	\ 		},							\
comment|/* Rear Right */
value|\ 		[3] = {							\ 			.type = SND_CHN_T_BR,				\ 			.members =					\ 			    SND_CHN_T_MASK_BR | SND_CHN_T_MASK_BC	\ 		},							\
comment|/* Center */
value|\ 		[4] = {							\ 			.type = SND_CHN_T_FC,				\ 			.members = SND_CHN_T_MASK_FC			\ 		},							\
comment|/* LFE */
value|\ 		[5] = {							\ 			.type = SND_CHN_T_LF,				\ 			.members = SND_CHN_T_MASK_LF			\ 		},							\
comment|/* Side Left */
value|\ 		[6] = {							\ 			.type = SND_CHN_T_SL,				\ 			.members = SND_CHN_T_MASK_SL			\ 		},							\
comment|/* Side Right */
value|\ 		[7] = {							\ 			.type = SND_CHN_T_SR,				\ 			.members = SND_CHN_T_MASK_SR			\ 		},							\ 		[8] = {							\ 			.type = SND_CHN_T_MAX,				\ 			.members = 0					\ 		}							\ 	},								\ 	.mask = SND_CHN_T_MASK_FL | SND_CHN_T_MASK_FR |			\ 		SND_CHN_T_MASK_BL | SND_CHN_T_MASK_BR |			\ 		SND_CHN_T_MASK_FC | SND_CHN_T_MASK_LF |			\ 		SND_CHN_T_MASK_SL | SND_CHN_T_MASK_SR,			\ 	.offset = {  0,  1,  4,  5,  2,  3, -1, -1, -1,			\ 		     6,  7, -1, -1, -1, -1, -1, -1, -1  }		\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SND_MATRIX_MAP_H_ */
end_comment

end_unit

