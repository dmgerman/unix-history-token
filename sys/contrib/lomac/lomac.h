begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOMAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOMAC_H_
end_define

begin_comment
comment|/*  * This file defines the `lattr_t' type, which represents  * the architecture-independent notion of LOMAC attributes.  *  * Each architecture must associate LOMAC attributes with subjects and  * objects.  This association can be implemented in an architecture-  * specific way.  However, when it comes time to make a decision by  * comparing two LOMAC attributes, the architecture-specific code should  * construct two instances of the architecture-independent lattr_t type  * and compare them using the lomac_must_demote() and lomac_must_deny()  * functions.  *  * The following two examples demonstrate how architecture-specific code   * might do this construction and comparison:  *  * EXAMPLE USAGE:  *   * Example 1:  subject x reads object y.  * (1)  a = LOMAC attributes of subject x  * (2)  b = LOMAC attributes of object y  * (3)  demote_result = lomac_must_demote( a, b );  * (4)  IF demote_result THEN  * (5)     IF subject x is running in "deny read instead of demote" mode THEN  * (6)        RETURN read denied  * (7)     ENDIF  * (8)     IF subject x is not running in "never demote" mode THEN  * (9)        demote subject x  * (10)    ENDIF  * (11) ENDIF  * (12) perform read on object y  *     *  * Example 2:  subject x writes object y.  * (50) a = LOMAC attributes of subject x  * (51) b = LOMAC attributes of object y  * (52) IF lomac_must_deny( a, b ) THEN  * (53)         return write denied  * (54) ELSE  * (55)         perform write operation on object y  * (56) ENDIF  *  * Lines 1, 2, 50, and 51 show the architecture-specific code  * constructing instances of lattr_t.  *  * Lines 5 and 8 ask "is the subject running in some mode?"  (See note  * on modes, below.)  The architecture-specific code must use these  * modes to determine when to call lomac_must_demote/deny() and when not  * to.  *  * Lines 6, 9, 53 and 55 show the architecture-specific code  * taking different actions depending on the results of calls to  * lomac_must_demote/deny().  The architecture-specific code is responsible  * for calling lomac_must_demote/deny() in the proper places, and carrying  * out the appropriate demotions and denials depending on the result.  *  *  * A NOTE ON LEVELS:  *  * LOMAC presently supports only two levels: 1 and 2.  Future versions  * of LOMAC may support more levels.  Architecture-specific code may  * assume that the LOWEST and HIGHEST constants defined below will  * always refer to the lowest and highest levels in the range.  They  * may also provide support for only two levels for the time being.  * However, architecture-specific code should try to minimize any other  * assumptions about levels, in order to make it easier to increase  * the level range in the future.  *  *  * A NOTE ON CATEGORIES:  *  * The lattr_t structure's `flags' field is intended to be a bitfield  * which architecture-specific code can use to implement categories.  * The lomac_must_deny() function interprets the bits in the flags field  * as categories.  A clear flags field means no categories.  *  * A NOTE ON MODES:  *  * LOMAC allows subjects to run in many modes, such as "never demote"  * or "no demote on IPC reads".  Support for these modes is entirely  * the responsibility of the architecture-specific code, because the  * architecture-independent code doesn't know about operations like  * "read" or "read on an IPC object".  *  *************************************************************************/
end_comment

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
operator|(
name|actor
operator|->
name|level
operator|>
name|target
operator|->
name|level
operator|)
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
block|{
return|return
literal|0
return|;
comment|/* allow */
block|}
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
comment|/* lomac.h */
end_comment

end_unit

