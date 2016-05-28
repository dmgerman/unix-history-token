begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, 2012, 2013 Spectra Logic Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * Authors: Justin T. Gibbs     (Spectra Logic Corporation)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/**  * \file zfsd_exception.h  *  * Definition of the ZfsdException class hierarchy.  All exceptions  * explicitly thrown by Zfsd are defined here.  *  * Header requirements:  *     #include<string>  *  *     #include<devdctl/exception.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZFSD_EXCEPTION_H_
end_ifndef

begin_define
define|#
directive|define
name|_ZFSD_EXCEPTION_H_
end_define

begin_comment
comment|/*=========================== Forward Declarations ===========================*/
end_comment

begin_struct_decl
struct_decl|struct
name|zpool_handle
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|zpool_handle
name|zpool_handle_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|nvlist
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|nvlist
name|nvlist_t
typedef|;
end_typedef

begin_comment
comment|/*============================= Class Definitions ============================*/
end_comment

begin_comment
comment|/*------------------------------- ZfsdException ------------------------------*/
end_comment

begin_comment
comment|/**  * \brief Class allowing unified reporting/logging of exceptional events.  */
end_comment

begin_decl_stmt
name|class
name|ZfsdException
range|:
name|public
name|DevdCtl
operator|::
name|Exception
block|{
name|public
operator|:
comment|/** 	 * \brief ZfsdException constructor allowing arbitrary string 	 *        data to be reported. 	 * 	 * \param fmt  Printf-like string format specifier. 	 */
name|ZfsdException
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
block|;
comment|/** 	 * \brief ZfsdException constructor allowing arbitrary string 	 *        data to be reported and associated with the configuration 	 *        data for a ZFS pool. 	 * 	 * \param pool  Pool handle describing the pool to which this 	 *              exception is associated. 	 * \param fmt   Printf-like string format specifier. 	 * 	 * Instantiation with this method is used to report global 	 * pool errors. 	 */
name|ZfsdException
argument_list|(
name|zpool_handle_t
operator|*
name|pool
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
block|;
comment|/** 	 * \brief ZfsdException constructor allowing arbitrary string 	 *        data to be reported and associated with the configuration 	 *        data for a ZFS pool. 	 * 	 * \param poolConfig  Pool configuration describing the pool to 	 *                    which this exception is associated. 	 * \param fmt         Printf-like string format specifier. 	 * 	 * Instantiation with this method is used to report global 	 * pool errors. 	 */
name|ZfsdException
argument_list|(
name|nvlist_t
operator|*
name|poolConfig
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
block|;
comment|/** 	 * \brief Emit exception data to syslog(3). 	 */
name|virtual
name|void
name|Log
argument_list|()
specifier|const
block|;
name|private
operator|:
name|nvlist_t
operator|*
name|m_poolConfig
block|;
name|nvlist_t
operator|*
name|m_vdevConfig
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ZFSD_EXCEPTION_H_ */
end_comment

end_unit

