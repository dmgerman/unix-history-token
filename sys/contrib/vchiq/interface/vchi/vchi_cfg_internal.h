begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2010-2012 Broadcom. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the above-listed copyright holders may not be used  *    to endorse or promote products derived from this software without  *    specific prior written permission.  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2, as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS  * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VCHI_CFG_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|VCHI_CFG_INTERNAL_H_
end_define

begin_comment
comment|/****************************************************************************************  * Control optimisation attempts.  ***************************************************************************************/
end_comment

begin_comment
comment|// Don't use lots of short-term locks - use great long ones, reducing the overall locks-per-second
end_comment

begin_define
define|#
directive|define
name|VCHI_COARSE_LOCKING
end_define

begin_comment
comment|// Avoid lock then unlock on exit from blocking queue operations (msg tx, bulk rx/tx)
end_comment

begin_comment
comment|// (only relevant if VCHI_COARSE_LOCKING)
end_comment

begin_define
define|#
directive|define
name|VCHI_ELIDE_BLOCK_EXIT_LOCK
end_define

begin_comment
comment|// Avoid lock on non-blocking peek
end_comment

begin_comment
comment|// (only relevant if VCHI_COARSE_LOCKING)
end_comment

begin_define
define|#
directive|define
name|VCHI_AVOID_PEEK_LOCK
end_define

begin_comment
comment|// Use one slot-handler thread per connection, rather than 1 thread dealing with all connections in rotation.
end_comment

begin_define
define|#
directive|define
name|VCHI_MULTIPLE_HANDLER_THREADS
end_define

begin_comment
comment|// Put free descriptors onto the head of the free queue, rather than the tail, so that we don't thrash
end_comment

begin_comment
comment|// our way through the pool of descriptors.
end_comment

begin_define
define|#
directive|define
name|VCHI_PUSH_FREE_DESCRIPTORS_ONTO_HEAD
end_define

begin_comment
comment|// Don't issue a MSG_AVAILABLE callback for every single message. Possibly only safe if VCHI_COARSE_LOCKING.
end_comment

begin_define
define|#
directive|define
name|VCHI_FEWER_MSG_AVAILABLE_CALLBACKS
end_define

begin_comment
comment|// Don't use message descriptors for TX messages that don't need them
end_comment

begin_define
define|#
directive|define
name|VCHI_MINIMISE_TX_MSG_DESCRIPTORS
end_define

begin_comment
comment|// Nano-locks for multiqueue
end_comment

begin_comment
comment|//#define VCHI_MQUEUE_NANOLOCKS
end_comment

begin_comment
comment|// Lock-free(er) dequeuing
end_comment

begin_comment
comment|//#define VCHI_RX_NANOLOCKS
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*VCHI_CFG_INTERNAL_H_*/
end_comment

end_unit

