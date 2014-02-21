begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * XZ decoder tester  *  * Author: Lasse Collin<lasse.collin@tukaani.org>  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  */
end_comment

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<linux/module.h>
end_include

begin_include
include|#
directive|include
file|<linux/fs.h>
end_include

begin_include
include|#
directive|include
file|<linux/uaccess.h>
end_include

begin_include
include|#
directive|include
file|<linux/crc32.h>
end_include

begin_include
include|#
directive|include
file|<linux/xz.h>
end_include

begin_comment
comment|/* Maximum supported dictionary size */
end_comment

begin_define
define|#
directive|define
name|DICT_MAX
value|(1<< 20)
end_define

begin_comment
comment|/* Device name to pass to register_chrdev(). */
end_comment

begin_define
define|#
directive|define
name|DEVICE_NAME
value|"xz_dec_test"
end_define

begin_comment
comment|/* Dynamically allocated device major number */
end_comment

begin_decl_stmt
specifier|static
name|int
name|device_major
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We reuse the same decoder state, and thus can decode only one  * file at a time.  */
end_comment

begin_decl_stmt
specifier|static
name|bool
name|device_is_open
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XZ decoder state */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|xz_dec
modifier|*
name|state
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return value of xz_dec_run(). We need to avoid calling xz_dec_run() after  * it has returned XZ_STREAM_END, so we make this static.  */
end_comment

begin_decl_stmt
specifier|static
name|enum
name|xz_ret
name|ret
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Input and output buffers. The input buffer is used as a temporary safe  * place for the data coming from the userspace.  */
end_comment

begin_decl_stmt
specifier|static
name|uint8_t
name|buffer_in
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint8_t
name|buffer_out
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structure to pass the input and output buffers to the XZ decoder.  * A few of the fields are never modified so we initialize them here.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|xz_buf
name|buffers
init|=
block|{
operator|.
name|in
operator|=
name|buffer_in
block|,
operator|.
name|out
operator|=
name|buffer_out
block|,
operator|.
name|out_size
operator|=
expr|sizeof
operator|(
name|buffer_out
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * CRC32 of uncompressed data. This is used to give the user a simple way  * to check that the decoder produces correct output.  */
end_comment

begin_decl_stmt
specifier|static
name|uint32_t
name|crc
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|xz_dec_test_open
parameter_list|(
name|struct
name|inode
modifier|*
name|i
parameter_list|,
name|struct
name|file
modifier|*
name|f
parameter_list|)
block|{
if|if
condition|(
name|device_is_open
condition|)
return|return
operator|-
name|EBUSY
return|;
name|device_is_open
operator|=
name|true
expr_stmt|;
name|xz_dec_reset
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|ret
operator|=
name|XZ_OK
expr_stmt|;
name|crc
operator|=
literal|0xFFFFFFFF
expr_stmt|;
name|buffers
operator|.
name|in_pos
operator|=
literal|0
expr_stmt|;
name|buffers
operator|.
name|in_size
operator|=
literal|0
expr_stmt|;
name|buffers
operator|.
name|out_pos
operator|=
literal|0
expr_stmt|;
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": opened\n"
argument_list|)
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|xz_dec_test_release
parameter_list|(
name|struct
name|inode
modifier|*
name|i
parameter_list|,
name|struct
name|file
modifier|*
name|f
parameter_list|)
block|{
name|device_is_open
operator|=
name|false
expr_stmt|;
if|if
condition|(
name|ret
operator|==
name|XZ_OK
condition|)
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": input was truncated\n"
argument_list|)
empty_stmt|;
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": closed\n"
argument_list|)
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Decode the data given to us from the userspace. CRC32 of the uncompressed  * data is calculated and is printed at the end of successful decoding. The  * uncompressed data isn't stored anywhere for further use.  *  * The .xz file must have exactly one Stream and no Stream Padding. The data  * after the first Stream is considered to be garbage.  */
end_comment

begin_function
specifier|static
name|ssize_t
name|xz_dec_test_write
parameter_list|(
name|struct
name|file
modifier|*
name|file
parameter_list|,
specifier|const
name|char
name|__user
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|,
name|loff_t
modifier|*
name|pos
parameter_list|)
block|{
name|size_t
name|remaining
decl_stmt|;
if|if
condition|(
name|ret
operator|!=
name|XZ_OK
condition|)
block|{
if|if
condition|(
name|size
operator|>
literal|0
condition|)
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": %zu bytes of "
literal|"garbage at the end of the file\n"
argument_list|,
argument|size
argument_list|)
empty_stmt|;
return|return
operator|-
name|ENOSPC
return|;
block|}
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": decoding %zu bytes of input\n"
argument_list|,
argument|size
argument_list|)
empty_stmt|;
name|remaining
operator|=
name|size
expr_stmt|;
while|while
condition|(
operator|(
name|remaining
operator|>
literal|0
operator|||
name|buffers
operator|.
name|out_pos
operator|==
name|buffers
operator|.
name|out_size
operator|)
operator|&&
name|ret
operator|==
name|XZ_OK
condition|)
block|{
if|if
condition|(
name|buffers
operator|.
name|in_pos
operator|==
name|buffers
operator|.
name|in_size
condition|)
block|{
name|buffers
operator|.
name|in_pos
operator|=
literal|0
expr_stmt|;
name|buffers
operator|.
name|in_size
operator|=
name|min
argument_list|(
name|remaining
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer_in
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|copy_from_user
argument_list|(
name|buffer_in
argument_list|,
name|buf
argument_list|,
name|buffers
operator|.
name|in_size
argument_list|)
condition|)
return|return
operator|-
name|EFAULT
return|;
name|buf
operator|+=
name|buffers
operator|.
name|in_size
expr_stmt|;
name|remaining
operator|-=
name|buffers
operator|.
name|in_size
expr_stmt|;
block|}
name|buffers
operator|.
name|out_pos
operator|=
literal|0
expr_stmt|;
name|ret
operator|=
name|xz_dec_run
argument_list|(
name|state
argument_list|,
operator|&
name|buffers
argument_list|)
expr_stmt|;
name|crc
operator|=
name|crc32
argument_list|(
name|crc
argument_list|,
name|buffer_out
argument_list|,
name|buffers
operator|.
name|out_pos
argument_list|)
expr_stmt|;
block|}
switch|switch
condition|(
name|ret
condition|)
block|{
case|case
name|XZ_OK
case|:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": XZ_OK\n"
argument_list|)
empty_stmt|;
return|return
name|size
return|;
case|case
name|XZ_STREAM_END
case|:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": XZ_STREAM_END, "
literal|"CRC32 = 0x%08X\n"
argument_list|,
argument|~crc
argument_list|)
empty_stmt|;
return|return
name|size
operator|-
name|remaining
operator|-
operator|(
name|buffers
operator|.
name|in_size
operator|-
name|buffers
operator|.
name|in_pos
operator|)
return|;
case|case
name|XZ_MEMLIMIT_ERROR
case|:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": XZ_MEMLIMIT_ERROR\n"
argument_list|)
empty_stmt|;
break|break;
case|case
name|XZ_FORMAT_ERROR
case|:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": XZ_FORMAT_ERROR\n"
argument_list|)
empty_stmt|;
break|break;
case|case
name|XZ_OPTIONS_ERROR
case|:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": XZ_OPTIONS_ERROR\n"
argument_list|)
empty_stmt|;
break|break;
case|case
name|XZ_DATA_ERROR
case|:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": XZ_DATA_ERROR\n"
argument_list|)
empty_stmt|;
break|break;
case|case
name|XZ_BUF_ERROR
case|:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": XZ_BUF_ERROR\n"
argument_list|)
empty_stmt|;
break|break;
default|default:
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": Bug detected!\n"
argument_list|)
empty_stmt|;
break|break;
block|}
return|return
operator|-
name|EIO
return|;
block|}
end_function

begin_comment
comment|/* Allocate the XZ decoder state and register the character device. */
end_comment

begin_function
specifier|static
name|int
name|__init
name|xz_dec_test_init
parameter_list|(
name|void
parameter_list|)
block|{
specifier|static
specifier|const
name|struct
name|file_operations
name|fileops
init|=
block|{
operator|.
name|owner
operator|=
name|THIS_MODULE
block|,
operator|.
name|open
operator|=
operator|&
name|xz_dec_test_open
block|,
operator|.
name|release
operator|=
operator|&
name|xz_dec_test_release
block|,
operator|.
name|write
operator|=
operator|&
name|xz_dec_test_write
block|}
decl_stmt|;
name|state
operator|=
name|xz_dec_init
argument_list|(
name|XZ_PREALLOC
argument_list|,
name|DICT_MAX
argument_list|)
expr_stmt|;
if|if
condition|(
name|state
operator|==
name|NULL
condition|)
return|return
operator|-
name|ENOMEM
return|;
name|device_major
operator|=
name|register_chrdev
argument_list|(
literal|0
argument_list|,
name|DEVICE_NAME
argument_list|,
operator|&
name|fileops
argument_list|)
expr_stmt|;
if|if
condition|(
name|device_major
operator|<
literal|0
condition|)
block|{
name|xz_dec_end
argument_list|(
name|state
argument_list|)
expr_stmt|;
return|return
name|device_major
return|;
block|}
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": module loaded\n"
argument_list|)
empty_stmt|;
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": Create a device node with "
literal|"'mknod "
argument|DEVICE_NAME
literal|" c %d 0' and write .xz files "
literal|"to it.\n"
argument_list|,
argument|device_major
argument_list|)
empty_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|__exit
name|xz_dec_test_exit
parameter_list|(
name|void
parameter_list|)
block|{
name|unregister_chrdev
argument_list|(
name|device_major
argument_list|,
name|DEVICE_NAME
argument_list|)
expr_stmt|;
name|xz_dec_end
argument_list|(
name|state
argument_list|)
expr_stmt|;
name|printk
argument_list|(
argument|KERN_INFO DEVICE_NAME
literal|": module unloaded\n"
argument_list|)
empty_stmt|;
block|}
end_function

begin_expr_stmt
name|module_init
argument_list|(
name|xz_dec_test_init
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|module_exit
argument_list|(
name|xz_dec_test_exit
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DESCRIPTION
argument_list|(
literal|"XZ decompressor tester"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
literal|"1.0"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_AUTHOR
argument_list|(
literal|"Lasse Collin<lasse.collin@tukaani.org>"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * This code is in the public domain, but in Linux it's simplest to just  * say it's GPL and consider the authors as the copyright holders.  */
end_comment

begin_expr_stmt
name|MODULE_LICENSE
argument_list|(
literal|"GPL"
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

