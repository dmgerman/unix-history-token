begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1985, 1991, 1993 Peter J. Nicklin.  * Copyright (c) 1991, 1993 Version Technology.  * All Rights Reserved.  *  * $License: VT.1.1 $  * Redistribution and use in source and binary forms,  with or without  * modification,  are permitted provided that the following conditions  * are met:  (1) Redistributions of source code must retain the  above  * copyright  notice,  this  list  of  conditions  and  the  following  * disclaimer.  (2) Redistributions in binary form must reproduce  the  * above  copyright notice,  this list of conditions and the following  * disclaimer in the  documentation  and/or other  materials  provided  * with  the  distribution.  (3) All advertising materials  mentioning  * features or  use  of  this  software  must  display  the  following  * acknowledgement:  ``This  product  includes  software  developed by  * Version Technology.''  Neither the name of Version  Technology  nor  * the  name  of  Peter J. Nicklin  may  be used to endorse or promote  * products derived from this software without specific prior  written  * permission.  *  * THIS SOFTWARE IS PROVIDED BY VERSION TECHNOLOGY ``AS IS''  AND  ANY  * EXPRESS OR IMPLIED WARRANTIES,  INCLUDING,  BUT NOT LIMITED TO, THE  * IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  VERSION  TECHNOLOGY  BE  * LIABLE  FOR ANY DIRECT,  INDIRECT,  INCIDENTAL, SPECIAL, EXEMPLARY,  * OR  CONSEQUENTIAL DAMAGES   (INCLUDING,   BUT   NOT   LIMITED   TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY  * OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT LIABILITY,  OR  TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING  IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE,  EVEN  IF  ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * Report problems and direct questions to nicklin@netcom.com  *  * $Header: Mkmf.h,v 4.7 93/05/25 22:16:40 nicklin Exp $  *  * Mkmf definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Buffer sizes  */
end_comment

begin_define
define|#
directive|define
name|ANSWERBUFSIZE
value|256
end_define

begin_comment
comment|/* interactive answer buffer size */
end_comment

begin_define
define|#
directive|define
name|INCLUDETABLESIZE
value|1021
end_define

begin_comment
comment|/* include file table size */
end_comment

begin_define
define|#
directive|define
name|SOURCETABLESIZE
value|1021
end_define

begin_comment
comment|/* source file table size */
end_comment

begin_define
define|#
directive|define
name|MACRODEFSIZE
value|16384
end_define

begin_comment
comment|/* macro definition body size */
end_comment

begin_define
define|#
directive|define
name|MACRONAMSIZE
value|64
end_define

begin_comment
comment|/* macro definition name size */
end_comment

begin_define
define|#
directive|define
name|MDEFTABLESIZE
value|127
end_define

begin_comment
comment|/* macro definition table size */
end_comment

begin_define
define|#
directive|define
name|RULETABSIZE
value|256
end_define

begin_comment
comment|/* rule table size */
end_comment

begin_define
define|#
directive|define
name|SFXTABSIZE
value|256
end_define

begin_comment
comment|/* suffix table size */
end_comment

begin_define
define|#
directive|define
name|SUFFIXSIZE
value|16
end_define

begin_comment
comment|/* suffix size */
end_comment

begin_comment
comment|/*  * Predefined macro names  */
end_comment

begin_define
define|#
directive|define
name|MCXXFLAGS
value|"CXXFLAGS"
end_define

begin_comment
comment|/* C++ flags macro for HP 'make'     */
end_comment

begin_define
define|#
directive|define
name|MCPXFLAGS
value|"C++FLAGS"
end_define

begin_comment
comment|/* C++ flags macro for SYSVR4 'make' */
end_comment

begin_define
define|#
directive|define
name|MCCFLAGS
value|"CCFLAGS"
end_define

begin_comment
comment|/* C++ flags macro for SunOS 'make'  */
end_comment

begin_define
define|#
directive|define
name|MCFLAGS
value|"CFLAGS"
end_define

begin_define
define|#
directive|define
name|MCOMPILESYSTYPE
value|"COMPILESYSTYPE"
end_define

begin_define
define|#
directive|define
name|MDESTDIR
value|"DEST"
end_define

begin_define
define|#
directive|define
name|MEXTERNALS
value|"EXTHDRS"
end_define

begin_define
define|#
directive|define
name|MFFLAGS
value|"FFLAGS"
end_define

begin_define
define|#
directive|define
name|MHEADERS
value|"HDRS"
end_define

begin_define
define|#
directive|define
name|MLDFLAGS
value|"LDFLAGS"
end_define

begin_define
define|#
directive|define
name|MLIBLIST
value|"LIBS"
end_define

begin_define
define|#
directive|define
name|MLIBRARY
value|"LIBRARY"
end_define

begin_define
define|#
directive|define
name|MLPATH
value|"LPATH"
end_define

begin_define
define|#
directive|define
name|MMAKEFILE
value|"MAKEFILE"
end_define

begin_define
define|#
directive|define
name|MOBJECTS
value|"OBJS"
end_define

begin_define
define|#
directive|define
name|MPFLAGS
value|"PFLAGS"
end_define

begin_define
define|#
directive|define
name|MPROGRAM
value|"PROGRAM"
end_define

begin_define
define|#
directive|define
name|MSOURCES
value|"SRCS"
end_define

begin_define
define|#
directive|define
name|MSUFFIX
value|"SUFFIX"
end_define

begin_define
define|#
directive|define
name|MSYSHDRS
value|"SYSHDRS"
end_define

begin_define
define|#
directive|define
name|MVPATH
value|"VPATH"
end_define

begin_comment
comment|/*  * Predefined $(macro) instances  */
end_comment

begin_define
define|#
directive|define
name|DCXXFLAGS
value|"$(CXXFLAGS)"
end_define

begin_comment
comment|/* C++ flags macro for HP 'make'     */
end_comment

begin_define
define|#
directive|define
name|DCPXFLAGS
value|"$(C++FLAGS)"
end_define

begin_comment
comment|/* C++ flags macro for SYSVR4 'make' */
end_comment

begin_define
define|#
directive|define
name|DCCFLAGS
value|"$(CCFLAGS)"
end_define

begin_comment
comment|/* C++ flags macro for SunOS 'make'  */
end_comment

begin_define
define|#
directive|define
name|DCFLAGS
value|"$(CFLAGS)"
end_define

begin_define
define|#
directive|define
name|DDESTDIR
value|"$(DEST)"
end_define

begin_define
define|#
directive|define
name|DEXTERNALS
value|"$(EXTHDRS)"
end_define

begin_define
define|#
directive|define
name|DFFLAGS
value|"$(FFLAGS)"
end_define

begin_define
define|#
directive|define
name|DHEADERS
value|"$(HDRS)"
end_define

begin_define
define|#
directive|define
name|DLDFLAGS
value|"$(LDFLAGS)"
end_define

begin_define
define|#
directive|define
name|DLIBLIST
value|"$(LIBS)"
end_define

begin_define
define|#
directive|define
name|DLIBRARY
value|"$(LIBRARY)"
end_define

begin_define
define|#
directive|define
name|DLPATH
value|"$(LPATH)"
end_define

begin_define
define|#
directive|define
name|DMAKEFILE
value|"$(MAKEFILE)"
end_define

begin_define
define|#
directive|define
name|DOBJECTS
value|"$(OBJS)"
end_define

begin_define
define|#
directive|define
name|DPFLAGS
value|"$(PFLAGS)"
end_define

begin_define
define|#
directive|define
name|DPROGRAM
value|"$(PROGRAM)"
end_define

begin_define
define|#
directive|define
name|DSOURCE
value|"$(SRCS)"
end_define

begin_define
define|#
directive|define
name|DSUFFIX
value|"$(SUFFIX)"
end_define

begin_define
define|#
directive|define
name|DSYSHDRS
value|"$(SYSHDRS)"
end_define

begin_define
define|#
directive|define
name|DVPATH
value|"$(VPATH)"
end_define

begin_comment
comment|/*  * Predefined ${macro} instances  */
end_comment

begin_define
define|#
directive|define
name|dCXXFLAGS
value|"${CXXFLAGS}"
end_define

begin_comment
comment|/* C++ flags macro for HP 'make'     */
end_comment

begin_define
define|#
directive|define
name|dCPXFLAGS
value|"${C++FLAGS}"
end_define

begin_comment
comment|/* C++ flags macro for SYSVR4 'make' */
end_comment

begin_define
define|#
directive|define
name|dCCFLAGS
value|"${CCFLAGS}"
end_define

begin_comment
comment|/* C++ flags macro for SunOS 'make'  */
end_comment

begin_define
define|#
directive|define
name|dCFLAGS
value|"${CFLAGS}"
end_define

begin_define
define|#
directive|define
name|dDESTDIR
value|"${DEST}"
end_define

begin_define
define|#
directive|define
name|dEXTERNALS
value|"${EXTHDRS}"
end_define

begin_define
define|#
directive|define
name|dFFLAGS
value|"${FFLAGS}"
end_define

begin_define
define|#
directive|define
name|dHEADERS
value|"${HDRS}"
end_define

begin_define
define|#
directive|define
name|dLDFLAGS
value|"${LDFLAGS}"
end_define

begin_define
define|#
directive|define
name|dLIBLIST
value|"${LIBS}"
end_define

begin_define
define|#
directive|define
name|dLIBRARY
value|"${LIBRARY}"
end_define

begin_define
define|#
directive|define
name|dLPATH
value|"${LPATH}"
end_define

begin_define
define|#
directive|define
name|dMAKEFILE
value|"${MAKEFILE}"
end_define

begin_define
define|#
directive|define
name|dOBJECTS
value|"${OBJS}"
end_define

begin_define
define|#
directive|define
name|dPFLAGS
value|"${PFLAGS}"
end_define

begin_define
define|#
directive|define
name|dPROGRAM
value|"${PROGRAM}"
end_define

begin_define
define|#
directive|define
name|dSOURCE
value|"${SRCS}"
end_define

begin_define
define|#
directive|define
name|dSUFFIX
value|"${SUFFIX}"
end_define

begin_define
define|#
directive|define
name|dSYSHDRS
value|"${SYSHDRS}"
end_define

begin_define
define|#
directive|define
name|dVPATH
value|"${VPATH}"
end_define

begin_comment
comment|/*  * Predefined macro values  */
end_comment

begin_define
define|#
directive|define
name|VERROR
value|-1
end_define

begin_define
define|#
directive|define
name|VUNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|VREADONLY
value|1
end_define

begin_define
define|#
directive|define
name|VREADWRITE
value|2
end_define

begin_define
define|#
directive|define
name|VDYNAMIC
value|3
end_define

begin_define
define|#
directive|define
name|VDESTDIR
value|4
end_define

begin_define
define|#
directive|define
name|VPROGRAM
value|5
end_define

begin_define
define|#
directive|define
name|VLIBRARY
value|6
end_define

begin_comment
comment|/*  * Predefined template suffixes  */
end_comment

begin_define
define|#
directive|define
name|SPROGRAM
value|".p"
end_define

begin_define
define|#
directive|define
name|SLIBRARY
value|".l"
end_define

begin_define
define|#
directive|define
name|SLIBRARY2
value|".L"
end_define

begin_comment
comment|/*  * Include statement styles  */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_NONE
value|0
end_define

begin_comment
comment|/* no include file */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_C
value|1
end_define

begin_comment
comment|/* #include "file" */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_CXX
value|2
end_define

begin_comment
comment|/* #include "file" for C++ */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_FORTRAN
value|3
end_define

begin_comment
comment|/* include "file" or #include "file" */
end_comment

begin_define
define|#
directive|define
name|INCLUDE_PASCAL
value|4
end_define

begin_comment
comment|/* #include "file" */
end_comment

begin_comment
comment|/*  * Marker to indicate start of included file dependencies  */
end_comment

begin_define
define|#
directive|define
name|DEPENDMARK
value|"###"
end_define

begin_comment
comment|/*  * Mkmf directories  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INSTALLDIR
end_ifndef

begin_define
define|#
directive|define
name|INSTALLDIR
value|"/usr/contrib"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MKMFLIB
value|"lib/mkmf"
end_define

end_unit

