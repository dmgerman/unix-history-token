begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TRACE.H: Declarations for internal trace functions. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_comment
comment|/* Trace variables. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace state transitions; 0=don't. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|atrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace attribute activity; 0=don't. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ctrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace context checking; 0=don't. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dtrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace declaration parsing; 0=don't.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|etrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace entity activity; 0=don't.*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gtrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace group creations; 0=don't. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|itrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace ID activity; 0=don't. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mtrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace MS activity; 0=don't. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ntrace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Switch: 1=trace data notation activity. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|emd
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For "EMD" parameter type in dtrace calls. */
end_comment

begin_decl_stmt
name|VOID
name|traceadl
name|P
argument_list|(
operator|(
expr|struct
name|ad
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracecon
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|parse
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracedcn
name|P
argument_list|(
operator|(
expr|struct
name|dcncb
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracedsk
name|P
argument_list|(
operator|(
expr|struct
name|tag
operator|*
operator|,
expr|struct
name|tag
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceecb
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|entity
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceend
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|thdr
operator|*
operator|,
expr|struct
name|mpos
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceesn
name|P
argument_list|(
operator|(
expr|struct
name|ne
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceetd
name|P
argument_list|(
operator|(
expr|struct
name|etd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceetg
name|P
argument_list|(
operator|(
expr|struct
name|tag
operator|*
operator|,
expr|struct
name|etd
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracegi
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|etd
operator|*
operator|,
expr|struct
name|thdr
operator|*
operator|,
expr|struct
name|mpos
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracegml
name|P
argument_list|(
operator|(
expr|struct
name|restate
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracegrp
name|P
argument_list|(
operator|(
expr|struct
name|etd
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceid
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|id
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracemd
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracemod
name|P
argument_list|(
operator|(
expr|struct
name|thdr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracems
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracengr
name|P
argument_list|(
operator|(
expr|struct
name|dcncb
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracepcb
name|P
argument_list|(
operator|(
expr|struct
name|parse
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracepro
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceset
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracesrm
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|entity
operator|*
operator|*
operator|,
name|UNCH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracestg
name|P
argument_list|(
operator|(
expr|struct
name|etd
operator|*
operator|,
name|int
operator|,
name|int
operator|,
expr|struct
name|etd
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracestk
name|P
argument_list|(
operator|(
expr|struct
name|tag
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|tracetkn
name|P
argument_list|(
operator|(
name|int
operator|,
name|UNCH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
name|traceval
name|P
argument_list|(
operator|(
expr|struct
name|parse
operator|*
operator|,
name|unsigned
name|int
operator|,
name|UNCH
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TRACEADL
parameter_list|(
name|al
parameter_list|)
value|((void)(atrace&& (traceadl(al), 1)))
end_define

begin_define
define|#
directive|define
name|TRACECON
parameter_list|(
name|etagimct
parameter_list|,
name|dostag
parameter_list|,
name|datarc
parameter_list|,
name|pcb
parameter_list|,
name|conrefsw
parameter_list|,
name|didreq
parameter_list|)
define|\
value|((void)(gtrace \&& (tracecon(etagimct, dostag, datarc, pcb, conrefsw, didreq), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEDCN
parameter_list|(
name|dcn
parameter_list|)
value|((void)(ntrace&& (tracedcn(dcn), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEDSK
parameter_list|(
name|pts
parameter_list|,
name|ptso
parameter_list|,
name|ts3
parameter_list|,
name|etictr
parameter_list|)
define|\
value|((void)(gtrace&& (tracedsk(pts, ptso, ts3, etictr), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEECB
parameter_list|(
name|action
parameter_list|,
name|p
parameter_list|)
define|\
value|((void)(etrace&& (traceecb(action, p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEEND
parameter_list|(
name|stagenm
parameter_list|,
name|mod
parameter_list|,
name|pos
parameter_list|,
name|rc
parameter_list|,
name|opt
parameter_list|)
define|\
value|((void)(ctrace&& (traceend(stagenm, mod, pos, rc, opt), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEESN
parameter_list|(
name|p
parameter_list|)
define|\
value|((void)((etrace || atrace || ntrace)&& (traceesn(p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEETD
parameter_list|(
name|p
parameter_list|)
value|((void)(gtrace&& (traceetd(p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEETG
parameter_list|(
name|pts
parameter_list|,
name|curetd
parameter_list|,
name|tsl
parameter_list|,
name|etagimct
parameter_list|)
define|\
value|((void)(gtrace&& (traceetg(pts, curetd, tsl, etagimct), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEGI
parameter_list|(
name|stagenm
parameter_list|,
name|gi
parameter_list|,
name|mod
parameter_list|,
name|pos
parameter_list|)
define|\
value|((void)(ctrace&& (tracegi(stagenm, gi, mod, pos), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEGML
parameter_list|(
name|scb
parameter_list|,
name|pss
parameter_list|,
name|conactsw
parameter_list|,
name|conact
parameter_list|)
define|\
value|((void)(trace&& (tracegml(scb, pss, conactsw, conact), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEGRP
parameter_list|(
name|p
parameter_list|)
value|((void)(gtrace&& (tracegrp(p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEID
parameter_list|(
name|action
parameter_list|,
name|p
parameter_list|)
value|((void)(itrace&& (traceid(action, p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEMD
parameter_list|(
name|p
parameter_list|)
value|((void)(dtrace&& (tracemd(p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEMOD
parameter_list|(
name|p
parameter_list|)
value|((void)(gtrace&& (tracemod(p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEMS
parameter_list|(
name|action
parameter_list|,
name|code
parameter_list|,
name|mslevel
parameter_list|,
name|msplevel
parameter_list|)
define|\
value|((void)(mtrace&& (tracems(action, code, mslevel, msplevel), 1)))
end_define

begin_define
define|#
directive|define
name|TRACENGR
parameter_list|(
name|p
parameter_list|)
value|((void)(gtrace&& (tracengr(p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEPCB
parameter_list|(
name|p
parameter_list|)
value|((void)(trace&& (tracepcb(p), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEPRO
parameter_list|()
value|(tracepro())
end_define

begin_define
define|#
directive|define
name|TRACESET
parameter_list|()
value|(traceset())
end_define

begin_define
define|#
directive|define
name|TRACESRM
parameter_list|(
name|action
parameter_list|,
name|pg
parameter_list|,
name|gi
parameter_list|)
define|\
value|((void)(etrace&& (tracesrm(action, pg, gi), 1)))
end_define

begin_define
define|#
directive|define
name|TRACESTG
parameter_list|(
name|curetd
parameter_list|,
name|dataret
parameter_list|,
name|rc
parameter_list|,
name|nextetd
parameter_list|,
name|mexts
parameter_list|)
define|\
value|((void)(gtrace&& (tracestg(curetd, dataret, rc, nextetd, mexts), 1)))
end_define

begin_define
define|#
directive|define
name|TRACESTK
parameter_list|(
name|pts
parameter_list|,
name|ts2
parameter_list|,
name|etictr
parameter_list|)
define|\
value|((void)(gtrace&& (tracestk(pts, ts2, etictr), 1)))
end_define

begin_define
define|#
directive|define
name|TRACETKN
parameter_list|(
name|scope
parameter_list|,
name|lextoke
parameter_list|)
define|\
value|((void)(trace&& (tracetkn(scope, lextoke), 1)))
end_define

begin_define
define|#
directive|define
name|TRACEVAL
parameter_list|(
name|pcb
parameter_list|,
name|atype
parameter_list|,
name|aval
parameter_list|,
name|tokencnt
parameter_list|)
define|\
value|((void)(atrace&& (traceval(pcb, atype, aval, tokencnt), 1)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not TRACE */
end_comment

begin_define
define|#
directive|define
name|TRACEADL
parameter_list|(
name|al
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACECON
parameter_list|(
name|etagimct
parameter_list|,
name|dostag
parameter_list|,
name|datarc
parameter_list|,
name|pcb
parameter_list|,
name|conrefsw
parameter_list|,
name|didreq
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEDCN
parameter_list|(
name|dcn
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEDSK
parameter_list|(
name|pts
parameter_list|,
name|ptso
parameter_list|,
name|ts3
parameter_list|,
name|etictr
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEECB
parameter_list|(
name|action
parameter_list|,
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEEND
parameter_list|(
name|stagenm
parameter_list|,
name|mod
parameter_list|,
name|pos
parameter_list|,
name|rc
parameter_list|,
name|opt
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEESN
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEETG
parameter_list|(
name|pts
parameter_list|,
name|curetd
parameter_list|,
name|tsl
parameter_list|,
name|etagimct
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEETD
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEGI
parameter_list|(
name|stagenm
parameter_list|,
name|gi
parameter_list|,
name|mod
parameter_list|,
name|pos
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEGML
parameter_list|(
name|scb
parameter_list|,
name|pss
parameter_list|,
name|conactsw
parameter_list|,
name|conact
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEGRP
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEID
parameter_list|(
name|action
parameter_list|,
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEMD
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEMOD
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEMS
parameter_list|(
name|action
parameter_list|,
name|code
parameter_list|,
name|mslevel
parameter_list|,
name|msplevel
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACENGR
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEPCB
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEPRO
parameter_list|()
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACESET
parameter_list|()
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACESRM
parameter_list|(
name|action
parameter_list|,
name|pg
parameter_list|,
name|gi
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACESTG
parameter_list|(
name|curetd
parameter_list|,
name|dataret
parameter_list|,
name|rc
parameter_list|,
name|nextetd
parameter_list|,
name|mexts
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACESTK
parameter_list|(
name|pts
parameter_list|,
name|ts2
parameter_list|,
name|etictr
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACETKN
parameter_list|(
name|scope
parameter_list|,
name|lextoke
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_define
define|#
directive|define
name|TRACEVAL
parameter_list|(
name|pcb
parameter_list|,
name|atype
parameter_list|,
name|aval
parameter_list|,
name|tokencnt
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TRACE */
end_comment

end_unit

