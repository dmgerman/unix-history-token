begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)filedesc.h	7.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FILEDESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_FILEDESC_H_
end_define

begin_comment
comment|/*  * This structure is used for the management of descriptors.  * It may be shared by multiple threads.  *  * A process is initially started out with NDFILE worth of  * descriptors, selected to be enough for typical applications  * based on the historic limit of 20 open files. Additional  * descriptors may be allocated up to a system defined limit  * defined by the global variable nofile; the initial value  * of nofile is set to NOFILE. The initial expansion is set to  * NDEXTENT; each time it runs out it is doubled until nofile  * is reached. NDEXTENT should be selected to be the biggest  * multiple of OFILESIZE (see below) that will fit in a  * power-of-two sized piece of memory.  */
end_comment

begin_define
define|#
directive|define
name|NDFILE
value|20
end_define

begin_define
define|#
directive|define
name|NDEXTENT
value|25
end_define

begin_struct
struct|struct
name|filedesc
block|{
name|struct
name|vnode
modifier|*
name|fd_cdir
decl_stmt|;
comment|/* current directory */
name|struct
name|vnode
modifier|*
name|fd_rdir
decl_stmt|;
comment|/* root directory */
name|u_short
name|fd_cmask
decl_stmt|;
comment|/* mask for file creation */
name|u_short
name|fd_refcnt
decl_stmt|;
comment|/* reference count */
name|short
name|fd_lastfile
decl_stmt|;
comment|/* high-water mark of fd_ofile */
name|short
name|fd_maxfiles
decl_stmt|;
comment|/* maximum number of open files */
name|struct
name|file
modifier|*
name|fd_ofile
index|[
name|NDFILE
index|]
decl_stmt|;
comment|/* file structures for open files */
name|struct
name|file
modifier|*
modifier|*
name|fd_moreofiles
decl_stmt|;
comment|/* the rest of the open files */
name|char
name|fd_ofileflags
index|[
name|NDFILE
index|]
decl_stmt|;
comment|/* per-process open file flags */
name|char
modifier|*
name|fd_moreofileflags
decl_stmt|;
comment|/* the rest of the open file flags */
name|long
name|fd_spare
decl_stmt|;
comment|/* unused to round up to power of two */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Per-process open flags.  */
end_comment

begin_define
define|#
directive|define
name|UF_EXCLOSE
value|0x01
end_define

begin_comment
comment|/* auto-close on exec */
end_comment

begin_define
define|#
directive|define
name|UF_MAPPED
value|0x02
end_define

begin_comment
comment|/* mapped from device */
end_comment

begin_comment
comment|/*  * Data structure access macros.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|vax
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|tahoe
argument_list|)
end_if

begin_define
define|#
directive|define
name|OFILE
parameter_list|(
name|fd
parameter_list|,
name|indx
parameter_list|)
value|((indx)< NDFILE ? \ 	(fd)->fd_ofile[indx] : \ 	(fd)->fd_moreofiles[(indx) - NDFILE])
end_define

begin_define
define|#
directive|define
name|OFILEFLAGS
parameter_list|(
name|fd
parameter_list|,
name|indx
parameter_list|)
value|((indx)< NDFILE ? \ 	(fd)->fd_ofileflags[indx] : \ 	(fd)->fd_moreofileflags[(indx) - NDFILE])
end_define

begin_define
define|#
directive|define
name|OFILESIZE
value|(sizeof(struct file *) + sizeof(char))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCC cannot handle above as lvalues */
end_comment

begin_function_decl
name|struct
name|file
modifier|*
modifier|*
name|ofilefunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ofileflagsfunc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OFILE
parameter_list|(
name|fd
parameter_list|,
name|indx
parameter_list|)
value|*ofilefunc(fd, indx)
end_define

begin_define
define|#
directive|define
name|OFILEFLAGS
parameter_list|(
name|fd
parameter_list|,
name|indx
parameter_list|)
value|*ofileflagsfunc(fd, indx)
end_define

begin_define
define|#
directive|define
name|OFILESIZE
value|(sizeof(struct file *) + sizeof(char))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Kernel global variables and routines.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|filedesc
modifier|*
name|fddup
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|nofile
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FILEDESC_H_ */
end_comment

end_unit

