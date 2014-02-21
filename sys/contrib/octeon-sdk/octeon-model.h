begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * File defining different Octeon model IDs and macros to  * compare them.  *  *<hr>$Revision: 70338 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__OCTEON_MODEL_H__
end_ifndef

begin_define
define|#
directive|define
name|__OCTEON_MODEL_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* NOTE: These must match what is checked in common-config.mk */
comment|/* Defines to represent the different versions of Octeon.  */
comment|/* IMPORTANT: When the default pass is updated for an Octeon Model, ** the corresponding change must also be made in the oct-sim script. */
comment|/* The defines below should be used with the OCTEON_IS_MODEL() macro to ** determine what model of chip the software is running on.  Models ending ** in 'XX' match multiple models (families), while specific models match only ** that model.  If a pass (revision) is specified, then only that revision ** will be matched.  Care should be taken when checking for both specific ** models and families that the specific models are checked for first. ** While these defines are similar to the processor ID, they are not intended ** to be used by anything other that the OCTEON_IS_MODEL framework, and ** the values are subject to change at anytime without notice. ** ** NOTE: only the OCTEON_IS_MODEL() macro/function and the OCTEON_CN* macros ** should be used outside of this file.  All other macros are for internal ** use only, and may change without notice. */
define|#
directive|define
name|OCTEON_FAMILY_MASK
value|0x00ffff00
comment|/* Flag bits in top byte */
define|#
directive|define
name|OM_IGNORE_REVISION
value|0x01000000
comment|/* Ignores revision in model checks */
define|#
directive|define
name|OM_CHECK_SUBMODEL
value|0x02000000
comment|/* Check submodels */
define|#
directive|define
name|OM_MATCH_PREVIOUS_MODELS
value|0x04000000
comment|/* Match all models previous than the one specified */
define|#
directive|define
name|OM_IGNORE_MINOR_REVISION
value|0x08000000
comment|/* Ignores the minor revison on newer parts */
define|#
directive|define
name|OM_FLAG_MASK
value|0xff000000
define|#
directive|define
name|OM_MATCH_5XXX_FAMILY_MODELS
value|0x20000000
comment|/* Match all cn5XXX Octeon models. */
define|#
directive|define
name|OM_MATCH_6XXX_FAMILY_MODELS
value|0x40000000
comment|/* Match all cn6XXX Octeon models. */
define|#
directive|define
name|OM_MATCH_F7XXX_FAMILY_MODELS
value|0x80000000
comment|/* Match all cnf7XXX Octeon models. */
comment|/*  * CNF7XXX models with new revision encoding  */
define|#
directive|define
name|OCTEON_CNF71XX_PASS1_0
value|0x000d9400
define|#
directive|define
name|OCTEON_CNF71XX
value|(OCTEON_CNF71XX_PASS1_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CNF71XX_PASS1_X
value|(OCTEON_CNF71XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
comment|/*  * CN6XXX models with new revision encoding  */
define|#
directive|define
name|OCTEON_CN68XX_PASS1_0
value|0x000d9100
define|#
directive|define
name|OCTEON_CN68XX_PASS1_1
value|0x000d9101
define|#
directive|define
name|OCTEON_CN68XX_PASS1_2
value|0x000d9102
define|#
directive|define
name|OCTEON_CN68XX_PASS2_0
value|0x000d9108
define|#
directive|define
name|OCTEON_CN68XX
value|(OCTEON_CN68XX_PASS2_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN68XX_PASS1_X
value|(OCTEON_CN68XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN68XX_PASS2_X
value|(OCTEON_CN68XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN68XX_PASS1
value|OCTEON_CN68XX_PASS1_X
define|#
directive|define
name|OCTEON_CN68XX_PASS2
value|OCTEON_CN68XX_PASS2_X
define|#
directive|define
name|OCTEON_CN66XX_PASS1_0
value|0x000d9200
define|#
directive|define
name|OCTEON_CN66XX_PASS1_2
value|0x000d9202
define|#
directive|define
name|OCTEON_CN66XX
value|(OCTEON_CN66XX_PASS1_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN66XX_PASS1_X
value|(OCTEON_CN66XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN63XX_PASS1_0
value|0x000d9000
define|#
directive|define
name|OCTEON_CN63XX_PASS1_1
value|0x000d9001
define|#
directive|define
name|OCTEON_CN63XX_PASS1_2
value|0x000d9002
define|#
directive|define
name|OCTEON_CN63XX_PASS2_0
value|0x000d9008
define|#
directive|define
name|OCTEON_CN63XX_PASS2_1
value|0x000d9009
define|#
directive|define
name|OCTEON_CN63XX_PASS2_2
value|0x000d900a
define|#
directive|define
name|OCTEON_CN63XX
value|(OCTEON_CN63XX_PASS2_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN63XX_PASS1_X
value|(OCTEON_CN63XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN63XX_PASS2_X
value|(OCTEON_CN63XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN61XX_PASS1_0
value|0x000d9300
define|#
directive|define
name|OCTEON_CN61XX
value|(OCTEON_CN61XX_PASS1_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN61XX_PASS1_X
value|(OCTEON_CN61XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
comment|/*  * CN5XXX models with new revision encoding  */
define|#
directive|define
name|OCTEON_CN58XX_PASS1_0
value|0x000d0300
define|#
directive|define
name|OCTEON_CN58XX_PASS1_1
value|0x000d0301
define|#
directive|define
name|OCTEON_CN58XX_PASS1_2
value|0x000d0303
define|#
directive|define
name|OCTEON_CN58XX_PASS2_0
value|0x000d0308
define|#
directive|define
name|OCTEON_CN58XX_PASS2_1
value|0x000d0309
define|#
directive|define
name|OCTEON_CN58XX_PASS2_2
value|0x000d030a
define|#
directive|define
name|OCTEON_CN58XX_PASS2_3
value|0x000d030b
define|#
directive|define
name|OCTEON_CN58XX
value|(OCTEON_CN58XX_PASS1_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN58XX_PASS1_X
value|(OCTEON_CN58XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN58XX_PASS2_X
value|(OCTEON_CN58XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN58XX_PASS1
value|OCTEON_CN58XX_PASS1_X
define|#
directive|define
name|OCTEON_CN58XX_PASS2
value|OCTEON_CN58XX_PASS2_X
define|#
directive|define
name|OCTEON_CN56XX_PASS1_0
value|0x000d0400
define|#
directive|define
name|OCTEON_CN56XX_PASS1_1
value|0x000d0401
define|#
directive|define
name|OCTEON_CN56XX_PASS2_0
value|0x000d0408
define|#
directive|define
name|OCTEON_CN56XX_PASS2_1
value|0x000d0409
define|#
directive|define
name|OCTEON_CN56XX
value|(OCTEON_CN56XX_PASS2_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN56XX_PASS1_X
value|(OCTEON_CN56XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN56XX_PASS2_X
value|(OCTEON_CN56XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN56XX_PASS1
value|OCTEON_CN56XX_PASS1_X
define|#
directive|define
name|OCTEON_CN56XX_PASS2
value|OCTEON_CN56XX_PASS2_X
define|#
directive|define
name|OCTEON_CN57XX
value|OCTEON_CN56XX
define|#
directive|define
name|OCTEON_CN57XX_PASS1
value|OCTEON_CN56XX_PASS1
define|#
directive|define
name|OCTEON_CN57XX_PASS2
value|OCTEON_CN56XX_PASS2
define|#
directive|define
name|OCTEON_CN55XX
value|OCTEON_CN56XX
define|#
directive|define
name|OCTEON_CN55XX_PASS1
value|OCTEON_CN56XX_PASS1
define|#
directive|define
name|OCTEON_CN55XX_PASS2
value|OCTEON_CN56XX_PASS2
define|#
directive|define
name|OCTEON_CN54XX
value|OCTEON_CN56XX
define|#
directive|define
name|OCTEON_CN54XX_PASS1
value|OCTEON_CN56XX_PASS1
define|#
directive|define
name|OCTEON_CN54XX_PASS2
value|OCTEON_CN56XX_PASS2
define|#
directive|define
name|OCTEON_CN50XX_PASS1_0
value|0x000d0600
define|#
directive|define
name|OCTEON_CN50XX
value|(OCTEON_CN50XX_PASS1_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN50XX_PASS1_X
value|(OCTEON_CN50XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN50XX_PASS1
value|OCTEON_CN50XX_PASS1_X
comment|/* NOTE: Octeon CN5000F model is not identifiable using the OCTEON_IS_MODEL()     functions, but are treated as CN50XX */
define|#
directive|define
name|OCTEON_CN52XX_PASS1_0
value|0x000d0700
define|#
directive|define
name|OCTEON_CN52XX_PASS2_0
value|0x000d0708
define|#
directive|define
name|OCTEON_CN52XX
value|(OCTEON_CN52XX_PASS2_0 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN52XX_PASS1_X
value|(OCTEON_CN52XX_PASS1_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN52XX_PASS2_X
value|(OCTEON_CN52XX_PASS2_0 | OM_IGNORE_MINOR_REVISION)
define|#
directive|define
name|OCTEON_CN52XX_PASS1
value|OCTEON_CN52XX_PASS1_X
define|#
directive|define
name|OCTEON_CN52XX_PASS2
value|OCTEON_CN52XX_PASS2_X
comment|/*  * CN3XXX models with old revision enconding  */
comment|//#define OCTEON_CN38XX_PASS1     0x000d0000    // is not supported
define|#
directive|define
name|OCTEON_CN38XX_PASS2
value|0x000d0001
define|#
directive|define
name|OCTEON_CN38XX_PASS3
value|0x000d0003
define|#
directive|define
name|OCTEON_CN38XX
value|(OCTEON_CN38XX_PASS3 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN36XX
value|OCTEON_CN38XX
define|#
directive|define
name|OCTEON_CN36XX_PASS2
value|OCTEON_CN38XX_PASS2
define|#
directive|define
name|OCTEON_CN36XX_PASS3
value|OCTEON_CN38XX_PASS3
comment|/* The OCTEON_CN31XX matches CN31XX models and the CN3020 */
define|#
directive|define
name|OCTEON_CN31XX_PASS1
value|0x000d0100
define|#
directive|define
name|OCTEON_CN31XX_PASS1_1
value|0x000d0102
define|#
directive|define
name|OCTEON_CN31XX
value|(OCTEON_CN31XX_PASS1 | OM_IGNORE_REVISION)
comment|/* This model is only used for internal checks, it ** is not a valid model for the OCTEON_MODEL environment variable. ** This matches the CN3010 and CN3005 but NOT the CN3020*/
define|#
directive|define
name|OCTEON_CN30XX_PASS1
value|0x000d0200
define|#
directive|define
name|OCTEON_CN30XX_PASS1_1
value|0x000d0202
define|#
directive|define
name|OCTEON_CN30XX
value|(OCTEON_CN30XX_PASS1 | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN3005_PASS1
value|(0x000d0210 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3005_PASS1_0
value|(0x000d0210 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3005_PASS1_1
value|(0x000d0212 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3005
value|(OCTEON_CN3005_PASS1 | OM_IGNORE_REVISION | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3010_PASS1
value|(0x000d0200 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3010_PASS1_0
value|(0x000d0200 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3010_PASS1_1
value|(0x000d0202 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3010
value|(OCTEON_CN3010_PASS1 | OM_IGNORE_REVISION | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3020_PASS1
value|(0x000d0110 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3020_PASS1_0
value|(0x000d0110 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3020_PASS1_1
value|(0x000d0112 | OM_CHECK_SUBMODEL)
define|#
directive|define
name|OCTEON_CN3020
value|(OCTEON_CN3020_PASS1 | OM_IGNORE_REVISION | OM_CHECK_SUBMODEL)
comment|/* This matches the complete family of CN3xxx CPUs, and not subsequent models */
define|#
directive|define
name|OCTEON_CN3XXX
value|(OCTEON_CN58XX_PASS1_0 | OM_MATCH_PREVIOUS_MODELS | OM_IGNORE_REVISION)
define|#
directive|define
name|OCTEON_CN5XXX
value|(OCTEON_CN58XX_PASS1_0 | OM_MATCH_5XXX_FAMILY_MODELS)
define|#
directive|define
name|OCTEON_CN6XXX
value|(OCTEON_CN63XX_PASS1_0 | OM_MATCH_6XXX_FAMILY_MODELS)
define|#
directive|define
name|OCTEON_CNF7XXX
value|(OCTEON_CNF71XX_PASS1_0 | OM_MATCH_F7XXX_FAMILY_MODELS)
comment|/* The revision byte (low byte) has two different encodings. ** CN3XXX: ** **     bits **<7:5>: reserved (0) **<4>:   alternate package **<3:0>: revision ** ** CN5XXX: ** **     bits **<7>:   reserved (0) **<6>:   alternate package **<5:3>: major revision **<2:0>: minor revision ** */
comment|/* Masks used for the various types of model/family/revision matching */
define|#
directive|define
name|OCTEON_38XX_FAMILY_MASK
value|0x00ffff00
define|#
directive|define
name|OCTEON_38XX_FAMILY_REV_MASK
value|0x00ffff0f
define|#
directive|define
name|OCTEON_38XX_MODEL_MASK
value|0x00ffff10
define|#
directive|define
name|OCTEON_38XX_MODEL_REV_MASK
value|(OCTEON_38XX_FAMILY_REV_MASK | OCTEON_38XX_MODEL_MASK)
comment|/* CN5XXX and later use different layout of bits in the revision ID field */
define|#
directive|define
name|OCTEON_58XX_FAMILY_MASK
value|OCTEON_38XX_FAMILY_MASK
define|#
directive|define
name|OCTEON_58XX_FAMILY_REV_MASK
value|0x00ffff3f
define|#
directive|define
name|OCTEON_58XX_MODEL_MASK
value|0x00ffffc0
define|#
directive|define
name|OCTEON_58XX_MODEL_REV_MASK
value|(OCTEON_58XX_FAMILY_REV_MASK | OCTEON_58XX_MODEL_MASK)
define|#
directive|define
name|OCTEON_58XX_MODEL_MINOR_REV_MASK
value|(OCTEON_58XX_MODEL_REV_MASK& 0x00fffff8)
define|#
directive|define
name|OCTEON_5XXX_MODEL_MASK
value|0x00ff0fc0
define|#
directive|define
name|__OCTEON_MATCH_MASK__
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(((x)& (z)) == ((y)& (z)))
comment|/* NOTE: This for internal use only!!!!! */
define|#
directive|define
name|__OCTEON_IS_MODEL_COMPILE__
parameter_list|(
name|arg_model
parameter_list|,
name|chip_model
parameter_list|)
define|\
value|((((arg_model& OCTEON_38XX_FAMILY_MASK)< OCTEON_CN58XX_PASS1_0)&& (\      ((((arg_model)& (OM_FLAG_MASK)) == (OM_IGNORE_REVISION | OM_CHECK_SUBMODEL)) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_38XX_MODEL_MASK)) || \      ((((arg_model)& (OM_FLAG_MASK)) == 0) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_38XX_FAMILY_REV_MASK)) || \      ((((arg_model)& (OM_FLAG_MASK)) == OM_IGNORE_REVISION) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_38XX_FAMILY_MASK)) || \      ((((arg_model)& (OM_FLAG_MASK)) == OM_CHECK_SUBMODEL) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_38XX_MODEL_REV_MASK)) || \      ((((arg_model)& (OM_MATCH_PREVIOUS_MODELS)) == OM_MATCH_PREVIOUS_MODELS) \&& (((chip_model)& OCTEON_38XX_MODEL_MASK)< ((arg_model)& OCTEON_38XX_MODEL_MASK))) \     )) || \     (((arg_model& OCTEON_38XX_FAMILY_MASK)>= OCTEON_CN58XX_PASS1_0)&& (\      ((((arg_model)& (OM_FLAG_MASK)) == (OM_IGNORE_REVISION | OM_CHECK_SUBMODEL)) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_58XX_MODEL_MASK)) || \      ((((arg_model)& (OM_FLAG_MASK)) == 0) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_58XX_FAMILY_REV_MASK)) || \      ((((arg_model)& (OM_FLAG_MASK)) == OM_IGNORE_MINOR_REVISION) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_58XX_MODEL_MINOR_REV_MASK)) || \      ((((arg_model)& (OM_FLAG_MASK)) == OM_IGNORE_REVISION) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_58XX_FAMILY_MASK)) || \      ((((arg_model)& (OM_FLAG_MASK)) == OM_CHECK_SUBMODEL) \&& __OCTEON_MATCH_MASK__((chip_model), (arg_model), OCTEON_58XX_MODEL_REV_MASK)) || \      ((((arg_model)& (OM_MATCH_5XXX_FAMILY_MODELS)) == OM_MATCH_5XXX_FAMILY_MODELS) \&& ((chip_model)>= OCTEON_CN58XX_PASS1_0)&& ((chip_model)< OCTEON_CN63XX_PASS1_0)) || \      ((((arg_model)& (OM_MATCH_6XXX_FAMILY_MODELS)) == OM_MATCH_6XXX_FAMILY_MODELS) \&& ((chip_model)>= OCTEON_CN63XX_PASS1_0)&& ((chip_model)< OCTEON_CNF71XX_PASS1_0)) || \      ((((arg_model)& (OM_MATCH_F7XXX_FAMILY_MODELS)) == OM_MATCH_F7XXX_FAMILY_MODELS) \&& ((chip_model)>= OCTEON_CNF71XX_PASS1_0)) || \      ((((arg_model)& (OM_MATCH_PREVIOUS_MODELS)) == OM_MATCH_PREVIOUS_MODELS) \&& (((chip_model)& OCTEON_58XX_MODEL_MASK)< ((arg_model)& OCTEON_58XX_MODEL_MASK))) \     )))
ifndef|#
directive|ifndef
name|OCTEON_IS_MODEL
if|#
directive|if
name|defined
argument_list|(
name|USE_RUNTIME_MODEL_CHECKS
argument_list|)
operator|||
name|defined
argument_list|(
name|__U_BOOT__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|CVMX_BUILD_FOR_TOOLCHAIN
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OCTEON_MODEL
argument_list|)
operator|)
comment|/* NOTE: This for internal use only!!!!! */
specifier|static
specifier|inline
name|int
name|__octeon_is_model_runtime__
parameter_list|(
name|uint32_t
name|model
parameter_list|)
block|{
name|uint32_t
name|cpuid
init|=
name|cvmx_get_proc_id
argument_list|()
decl_stmt|;
comment|/* Check for special case of mismarked 3005 samples. We only need to check         if the sub model isn't being ignored */
if|if
condition|(
operator|(
name|model
operator|&
name|OM_CHECK_SUBMODEL
operator|)
operator|==
name|OM_CHECK_SUBMODEL
condition|)
block|{
if|if
condition|(
name|cpuid
operator|==
name|OCTEON_CN3010_PASS1
operator|&&
operator|(
name|cvmx_read_csr
argument_list|(
literal|0x80011800800007B8ull
argument_list|)
operator|&
operator|(
literal|1ull
operator|<<
literal|34
operator|)
operator|)
condition|)
name|cpuid
operator||=
literal|0x10
expr_stmt|;
block|}
return|return
operator|(
name|__OCTEON_IS_MODEL_COMPILE__
argument_list|(
name|model
argument_list|,
name|cpuid
argument_list|)
operator|)
return|;
block|}
comment|/* The OCTEON_IS_MODEL macro should be used for all Octeon model checking done ** in a program. ** This should be kept runtime if at all possible  and must be conditionalized ** with OCTEON_IS_COMMON_BINARY() if runtime checking support is required. ** ** Use of the macro in preprocessor directives ( #if OCTEON_IS_MODEL(...) ) ** is NOT SUPPORTED, and should be replaced with CVMX_COMPILED_FOR() ** I.e.: **  #if OCTEON_IS_MODEL(OCTEON_CN56XX)  ->  #if CVMX_COMPILED_FOR(OCTEON_CN56XX) */
define|#
directive|define
name|OCTEON_IS_MODEL
parameter_list|(
name|x
parameter_list|)
value|__octeon_is_model_runtime__(x)
define|#
directive|define
name|OCTEON_IS_COMMON_BINARY
parameter_list|()
value|1
undef|#
directive|undef
name|OCTEON_MODEL
else|#
directive|else
define|#
directive|define
name|CVMX_COMPILED_FOR
parameter_list|(
name|x
parameter_list|)
value|__OCTEON_IS_MODEL_COMPILE__(x, OCTEON_MODEL)
define|#
directive|define
name|OCTEON_IS_MODEL
parameter_list|(
name|x
parameter_list|)
define|\
value|(((x& (OM_IGNORE_REVISION | OM_IGNORE_MINOR_REVISION)) != 0) \     ? __OCTEON_IS_MODEL_COMPILE__(x, OCTEON_MODEL) \     : __OCTEON_IS_MODEL_COMPILE__(x, cvmx_get_proc_id()))
define|#
directive|define
name|OCTEON_IS_COMMON_BINARY
parameter_list|()
value|0
endif|#
directive|endif
endif|#
directive|endif
name|int
name|octeon_model_version_check
parameter_list|(
name|uint32_t
name|chip_id
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|octeon_model_get_string
parameter_list|(
name|uint32_t
name|chip_id
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|octeon_model_get_string_buffer
parameter_list|(
name|uint32_t
name|chip_id
parameter_list|,
name|char
modifier|*
name|buffer
parameter_list|)
function_decl|;
comment|/**                                                                            * Return the octeon family, i.e., ProcessorID of the PrID register.  *  * @return the octeon family on success, ((unint32_t)-1) on error.  */
specifier|static
specifier|inline
name|uint32_t
name|cvmx_get_octeon_family
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|USE_RUNTIME_MODEL_CHECKS
argument_list|)
operator|||
name|defined
argument_list|(
name|__U_BOOT__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
operator|)
operator|||
name|defined
argument_list|(
name|CVMX_BUILD_FOR_TOOLCHAIN
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|)
return|return
operator|(
name|cvmx_get_proc_id
argument_list|()
operator|&
name|OCTEON_FAMILY_MASK
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|OCTEON_MODEL
operator|&
name|OCTEON_FAMILY_MASK
operator|)
return|;
endif|#
directive|endif
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __OCTEON_MODEL_H__ */
end_comment

end_unit

