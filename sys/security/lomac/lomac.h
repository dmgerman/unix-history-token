begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOMAC_H_
end_ifndef

begin_define
define|#
directive|define
name|LOMAC_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|LOMAC_LOWEST_LEVEL
init|=
literal|1
block|,
name|LOMAC_HIGHEST_LEVEL
init|=
literal|2
block|}
name|level_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|level_t
name|level
decl_stmt|;
comment|/* level (an integer range) */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* category flags */
block|}
name|lattr_t
typedef|;
end_typedef

begin_comment
comment|/* lomac attribute structure type */
end_comment

begin_comment
comment|/* lomac_must_demote()  *  * in:     actor  - attributes of a subject that has or will perform an  *                  operation that may require LOMAC to demote it.  *         target - attributes of the object that is or was the operand.  * out:    nothing  * return: value   condition  *         -----   ---------  *           0     LOMAC should not demote the subject  *           1     LOMAC should demote the subject  *  * This function is a predicate which decides whether or not LOMAC should  * demote the subject with attributes `actor' after it performs an operation  * (probably some kind of a read operation) on the object with attributes   * `target'.  *  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|lomac_must_demote
parameter_list|(
specifier|const
name|lattr_t
modifier|*
name|actor
parameter_list|,
specifier|const
name|lattr_t
modifier|*
name|target
parameter_list|)
block|{
return|return
operator|(
name|actor
operator|->
name|level
operator|>
name|target
operator|->
name|level
operator|)
return|;
block|}
end_function

begin_comment
comment|/* lomac_must_deny()  *  * in:     actor  - attributes of a subject that wants to perform some  *                  operation that requires LOMAC to make an allow/deny  *                  decision.  *         target - attributes of the subject or object the above subject  *                  will operate upon.  * out:    nothing  * return: value     condition  *         -----     ---------  *           0       LOMAC should allow the operation  *           1       LOMAC should deny the operation  *  * This function is a predicate which decides whether or not LOMAC should  * allow the subject with attributes `actor' to perform some operation  * (probably some kind of write or kill operation) on the subject or object  * with attributes `target'.  *  * The flags are two words: the low word is to be used for categories,  * and the high word is meant to hold implementation-dependent flags that  * are not category-related.  *  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|lomac_must_deny
parameter_list|(
specifier|const
name|lattr_t
modifier|*
name|actor
parameter_list|,
specifier|const
name|lattr_t
modifier|*
name|target
parameter_list|)
block|{
if|if
condition|(
name|actor
operator|->
name|level
operator|>=
name|target
operator|->
name|level
condition|)
return|return
literal|0
return|;
comment|/* allow */
if|if
condition|(
name|target
operator|->
name|flags
operator|&
literal|0xffff
condition|)
block|{
if|if
condition|(
operator|(
name|actor
operator|->
name|flags
operator|&
name|target
operator|->
name|flags
operator|&
literal|0xffff
operator|)
operator|==
operator|(
name|target
operator|->
name|flags
operator|&
literal|0xffff
operator|)
condition|)
block|{
return|return
literal|0
return|;
comment|/* allow */
block|}
block|}
return|return
literal|1
return|;
comment|/* deny */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOMAC_H */
end_comment

end_unit

