begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file        lzma/hardware.h  * \brief       Hardware information  *  * Since liblzma can consume a lot of system resources, it also provides  * ways to limit the resource usage. Applications linking against liblzma  * need to do the actual decisions how much resources to let liblzma to use.  * To ease making these decisions, liblzma provides functions to find out  * the relevant capabilities of the underlaying hardware. Currently there  * is only a function to find out the amount of RAM, but in the future there  * will be also a function to detect how many concurrent threads the system  * can run.  *  * \note        On some operating systems, these function may temporarily  *              load a shared library or open file descriptor(s) to find out  *              the requested hardware information. Unless the application  *              assumes that specific file descriptors are not touched by  *              other threads, this should have no effect on thread safety.  *              Possible operations involving file descriptors will restart  *              the syscalls if they return EINTR.  */
end_comment

begin_comment
comment|/*  * Author: Lasse Collin  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  *  * See ../lzma.h for information about liblzma as a whole.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LZMA_H_INTERNAL
end_ifndef

begin_error
error|#
directive|error
error|Never include this file directly. Use<lzma.h> instead.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**  * \brief       Get the total amount of physical memory (RAM) in bytes  *  * This function may be useful when determining a reasonable memory  * usage limit for decompressing or how much memory it is OK to use  * for compressing.  *  * \return      On success, the total amount of physical memory in bytes  *              is returned. If the amount of RAM cannot be determined,  *              zero is returned. This can happen if an error occurs  *              or if there is no code in liblzma to detect the amount  *              of RAM on the specific operating system.  */
end_comment

begin_extern
extern|extern LZMA_API(uint64_t
end_extern

begin_macro
unit|)
name|lzma_physmem
argument_list|(
argument|void
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * \brief       Get the number of processor cores or threads  *  * This function may be useful when determining how many threads to use.  * If the hardware supports more than one thread per CPU core, the number  * of hardware threads is returned if that information is available.  *  * \brief       On success, the number of available CPU threads or cores is  *              returned. If this information isn't available or an error  *              occurs, zero is returned.  */
end_comment

begin_extern
extern|extern LZMA_API(uint32_t
end_extern

begin_macro
unit|)
name|lzma_cputhreads
argument_list|(
argument|void
argument_list|)
end_macro

begin_expr_stmt
name|lzma_nothrow
expr_stmt|;
end_expr_stmt

end_unit

