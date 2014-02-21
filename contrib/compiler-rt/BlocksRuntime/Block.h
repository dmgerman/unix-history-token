begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Block.h  *  * Copyright 2008-2010 Apple, Inc. Permission is hereby granted, free of charge,  * to any person obtaining a copy of this software and associated documentation  * files (the "Software"), to deal in the Software without restriction,  * including without limitation the rights to use, copy, modify, merge, publish,  * distribute, sublicense, and/or sell copies of the Software, and to permit  * persons to whom the Software is furnished to do so, subject to the following  * conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BLOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_BLOCK_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BLOCK_EXPORT
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|BLOCK_EXPORT
value|extern "C"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLOCK_EXPORT
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* Create a heap based copy of a Block or simply add a reference to an existing one.  * This must be paired with Block_release to recover memory, even when running  * under Objective-C Garbage Collection.  */
name|BLOCK_EXPORT
name|void
modifier|*
name|_Block_copy
parameter_list|(
specifier|const
name|void
modifier|*
name|aBlock
parameter_list|)
function_decl|;
comment|/* Lose the reference, and if heap based and last reference, recover the memory. */
name|BLOCK_EXPORT
name|void
name|_Block_release
parameter_list|(
specifier|const
name|void
modifier|*
name|aBlock
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Type correct macros. */
end_comment

begin_define
define|#
directive|define
name|Block_copy
parameter_list|(
modifier|...
parameter_list|)
value|((__typeof(__VA_ARGS__))_Block_copy((const void *)(__VA_ARGS__)))
end_define

begin_define
define|#
directive|define
name|Block_release
parameter_list|(
modifier|...
parameter_list|)
value|_Block_release((const void *)(__VA_ARGS__))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

