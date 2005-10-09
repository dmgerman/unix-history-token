begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: journal.h,v 1.23.12.3 2004/03/08 09:04:36 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_JOURNAL_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_JOURNAL_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Database journalling.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dns/diff.h>
end_include

begin_include
include|#
directive|include
file|<dns/rdata.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*  * A dns_journal_t represents an open journal file.  This is an opaque type.  *  * A particular dns_journal_t object may be opened for writing, in which case  * it can be used for writing transactions to a journal file, or it can be  * opened for reading, in which case it can be used for reading transactions  * from (iterating over) a journal file.  A single dns_journal_t object may  * not be used for both purposes.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dns_journal
name|dns_journal_t
typedef|;
end_typedef

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/**************************************************************************/
name|isc_result_t
name|dns_db_createsoatuple
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|ver
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_diffop_t
name|op
parameter_list|,
name|dns_difftuple_t
modifier|*
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a diff tuple for the current database SOA.  * XXX this probably belongs somewhere else.  */
end_comment

begin_define
define|#
directive|define
name|DNS_SERIAL_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)(((a) - (b))& 0xFFFFFFFF)> 0)
end_define

begin_define
define|#
directive|define
name|DNS_SERIAL_GE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)(((a) - (b))& 0xFFFFFFFF)>= 0)
end_define

begin_comment
comment|/*  * Compare SOA serial numbers.  DNS_SERIAL_GT(a, b) returns true iff  * a is "greater than" b where "greater than" is as defined in RFC1982.  * DNS_SERIAL_GE(a, b) returns true iff a is "greater than or equal to" b.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Journal object creation and destruction.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_open
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|isc_boolean_t
name|write
parameter_list|,
name|dns_journal_t
modifier|*
modifier|*
name|journalp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Open the journal file 'filename' and create a dns_journal_t object for it.  *  * If 'write' is ISC_TRUE, the journal is open for writing.  If it does  * not exist, it is created.  *  * If 'write' is ISC_FALSE, the journal is open for reading.  If it does  * not exist, ISC_R_NOTFOUND is returned.  */
end_comment

begin_function_decl
name|void
name|dns_journal_destroy
parameter_list|(
name|dns_journal_t
modifier|*
modifier|*
name|journalp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a dns_journal_t, closing any open files and freeing its memory.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Writing transactions to journals.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_begin_transaction
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Prepare to write a new transaction to the open journal file 'j'.  *  * Requires:  *      'j' is open for writing.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_writediff
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Write 'diff' to the current transaction of journal file 'j'.  *  * Requires:  *      'j' is open for writing and dns_journal_begin_transaction()  * 	has been called.  *  * 	'diff' is a full or partial, correctly ordered IXFR  *      difference sequence.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_commit
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Commit the current transaction of journal file 'j'.  *  * Requires:  *      'j' is open for writing and dns_journal_begin_transaction()  * 	has been called.  *  *      dns_journal_writediff() has been called one or more times  * 	to form a complete, correctly ordered IXFR difference  *      sequence.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_write_transaction
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|,
name|dns_diff_t
modifier|*
name|diff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Write a complete transaction at once to a journal file,  * sorting it if necessary, and commit it.  Equivalent to calling  * dns_diff_sort(), dns_journal_begin_transaction(),  * dns_journal_writediff(), and dns_journal_commit().  *  * Requires:  *      'j' is open for writing.  *  * 	'diff' contains exactly one SOA deletion, one SOA addition  *       with a greater serial number, and possibly other changes,  *       in arbitrary order.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Reading transactions from journals.  */
end_comment

begin_function_decl
name|isc_uint32_t
name|dns_journal_first_serial
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_uint32_t
name|dns_journal_last_serial
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the first and last addressable serial number in the journal.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_iter_init
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|,
name|isc_uint32_t
name|begin_serial
parameter_list|,
name|isc_uint32_t
name|end_serial
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Prepare to iterate over the transactions that will bring the database  * from SOA serial number 'begin_serial' to 'end_serial'.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_RANGE	begin_serial is outside the addressable range.  *	ISC_R_NOTFOUND	begin_serial is within the range of adressable  *			serial numbers covered by the journal, but  *			this particular serial number does not exist.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_first_rr
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|dns_journal_next_rr
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Position the iterator at the first/next RR in a journal  * transaction sequence established using dns_journal_iter_init().  *  * Requires:  *      dns_journal_iter_init() has been called.  *  */
end_comment

begin_function_decl
name|void
name|dns_journal_current_rr
parameter_list|(
name|dns_journal_t
modifier|*
name|j
parameter_list|,
name|dns_name_t
modifier|*
modifier|*
name|name
parameter_list|,
name|isc_uint32_t
modifier|*
name|ttl
parameter_list|,
name|dns_rdata_t
modifier|*
modifier|*
name|rdata
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the name, ttl, and rdata of the current journal RR.  *  * Requires:  *      The last call to dns_journal_first_rr() or dns_journal_next_rr()  *      returned ISC_R_SUCCESS.  */
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  * Database roll-forward.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_rollforward
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|db
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Roll forward (play back) the journal file "filename" into the  * database "db".  This should be called when the server starts  * after a shutdown or crash.  *  * Requires:  *      'mctx' is a valid memory context.  *	'db' is a valid database which does not have a version  *           open for writing.  *      'filename' is the name of the journal file belonging to 'db'.  *  * Returns:  *	DNS_R_NOJOURNAL when journal does not exist.  *	ISC_R_NOTFOUND when current serial in not in journal.  *	ISC_R_RANGE when current serial in not in journals range.  *	ISC_R_SUCCESS journal has been applied successfully to database.  *	others  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_print
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For debugging not general use */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_diff
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_db_t
modifier|*
name|dba
parameter_list|,
name|dns_dbversion_t
modifier|*
name|dbvera
parameter_list|,
name|dns_db_t
modifier|*
name|dbb
parameter_list|,
name|dns_dbversion_t
modifier|*
name|dbverb
parameter_list|,
specifier|const
name|char
modifier|*
name|journal_filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Compare the databases 'dba' and 'dbb' and generate a journal  * entry containing the changes to make 'dba' from 'dbb' (note  * the order).  This journal entry will consist of a single,  * possibly very large transaction.  Append the journal  * entry to the journal file specified by 'journal_filename'.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_journal_compact
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|char
modifier|*
name|filename
parameter_list|,
name|isc_uint32_t
name|serial
parameter_list|,
name|isc_uint32_t
name|target_size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attempt to compact the journal if it is greater that 'target_size'.  * Changes from 'serial' onwards will be preserved.  If the journal  * exists and is non-empty 'serial' must exist in the journal.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_JOURNAL_H */
end_comment

end_unit

