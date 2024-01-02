/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 1;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static int nomodbuttons                  = 1;   /* allow client mouse button bindings that have no modifier */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 0;   /* 0 means derive from font, >= 1 explicit height */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const int horizpadbar             = 2;   /* horizontal padding for statusbar */
static const int vertpadbar              = 0;   /* vertical padding for statusbar */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */



/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = { "monospace:size=10" };
static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";



static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
};

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};





/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

/* grid of tags */
#define SWITCHTAG_UP                1 << 0
#define SWITCHTAG_DOWN              1 << 1
#define SWITCHTAG_LEFT              1 << 2
#define SWITCHTAG_RIGHT             1 << 3
#define SWITCHTAG_TOGGLETAG         1 << 4
#define SWITCHTAG_TAG               1 << 5
#define SWITCHTAG_VIEW              1 << 6
#define SWITCHTAG_TOGGLEVIEW        1 << 7

static const int tagrows = 2;

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
	RULE(.class = "Gimp", .tags = 1 << 4)
	RULE(.class = "Firefox", .tags = 1 << 7)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_taggrid,            draw_taggrid,           click_taggrid,           NULL,                    "taggrid" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "|||",      col },
	{ "[D]",      deck },
	{ "(@)",      spiral },
	{ "[\\]",     dwindle },
	{ "HHH",      grid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "###",      nrowgrid },
};


/* key definitions */
#define Altkey Mod1Mask
#define Super Mod4Mask
#define XF86XK_AudioLowerVolume 0x1008FF11
#define XF86XK_AudioMute        0x1008FF12
#define XF86XK_AudioRaiseVolume 0x1008FF13
#define TAGKEYS(KEY,TAG) \
	{ Super,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ Super|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Super|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ Super|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { "st", NULL };
static const char *toggle_terminal[] = { "alacritty", NULL };
static const char *firefox[] = { "firefox", NULL };
static const char *rofi[] = { "rofi", "-show", "drun" };
/* print screen */
//static const char *prtsr[] = { "maim", "-s", "$HOME/Pictures/Screenshots/$(date '+%Y-%m-%d-%H:%M:%S').png", NULL };
//static const char *prtsr_full[] = { "maim", "$HOME/Pictures/Screenshots/$(date '+%Y-%m-%d-%H:%M:%S').png", NULL };
static const char prtsr[] = "maim -s ~/Pictures/Screenshots/$(date '+%Y-%m-%d-%H:%M:%S').png";
static const char prtsr_full[] = "maim  ~/Pictures/Screenshots/$(date '+%Y-%m-%d-%H:%M:%S').png";


static const Key keys[] = {
	/* modifier                     key            function                argument */
  /* dwm */
	{ControlMask|Altkey,          XK_q,       quit,           {0} },
  /* love */
  { Super,                      XK_Return,  spawn,          {.v = toggle_terminal} },
  { Super,                      XK_q,       spawn,          {.v = firefox} },
  { Super,                      XK_e,       spawn,          SHCMD("nemo") },
  { Super,                      XK_c,       spawn,          SHCMD("linuxqq") },
  { Super,                      XK_d,       spawn,          SHCMD("obsidian") },
  /* launcher */
  { Altkey,                     XK_c,       spawn,          {.v = rofi} },
	{ Super,                      XK_p,       spawn,          {.v = dmenucmd } },
  /* status bar */
	{ Super,                      XK_b,       togglebar,      {0} },
  /* shortcuts */
  { Super,                      XK_u,       spawn,          SHCMD(prtsr_full) },
  { Super|ShiftMask,            XK_u,       spawn,          SHCMD(prtsr) },
  //{ Super,                      XK_u,       spawn,          SHCMD("maim -s ~/Pictures/Screenshots/$(date '+%Y-%m-%d-%H:%M:%S').png") },
  //{ Super|ShiftMask,            XK_u,       spawn,          SHCMD("maim ~/Pictures/Screenshots/$(date '+%Y-%m-%d-%H:%M:%S').png") },
  { 0,    XF86XK_AudioRaiseVolume,          spawn,          SHCMD("volume up") },
  { 0,    XF86XK_AudioLowerVolume,          spawn,          SHCMD("volume down") },
  { 0,    XF86XK_AudioMute,                 spawn,          SHCMD("volume toggle") },
  /* client */
	{ Altkey|ShiftMask,               XK_q,       killclient,       {0} },
	{ Altkey|ShiftMask,               XK_Return,  zoom,             {0} },
  { Altkey,                         XK_j,       focusstack,       {.i = +1} },
  { Altkey,                         XK_k,       focusstack,       {.i = -1} },
  { Altkey|ShiftMask,               XK_j,       movestack,        {.i = +1} },
  { Altkey|ShiftMask,               XK_k,       movestack,        {.i = -1} },
	{ Altkey|ShiftMask,               XK_h,       setmfact,         {.f = -0.05} },
	{ Altkey|ShiftMask,               XK_l,       setmfact,         {.f = +0.05} },
  { Altkey|ShiftMask,               XK_space,   togglefloating,   {0} },
  { Altkey,                         XK_f,       togglefullscreen, {0} },
	{ Super,                          XK_Tab,     view,             {0} },
	{ Altkey,                         XK_e,       showhideclient,   {0} },

  /* layout */
	{ Super,                      XK_t,       setlayout,      {.v = &layouts[0]} },
	{ Super,                      XK_f,       setlayout,      {.v = &layouts[1]} },
	{ Super,                      XK_m,       setlayout,      {.v = &layouts[2]} },
  { Super,                      XK_s,       setlayout,      {.v = &layouts[3]} },
  { Super|ShiftMask,            XK_s,       setlayout,      {.v = &layouts[4]} },
	{ Super,                      XK_p,       cyclelayout,            {.i = -1 } },
	{ Super,                      XK_n,       cyclelayout,            {.i = +1 } },

  { Altkey|ShiftMask,           XK_i,       incnmaster,     {.i = +1 } },
	{ Altkey|ShiftMask,           XK_d,       incnmaster,     {.i = -1 } },
	{ Super|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
	{ Super|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
	{ Super|ShiftMask,             XK_o,          setcfact,               {0} },
	{ Super|Mod4Mask,              XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
	{ Super|Mod4Mask,              XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
	{ Super|Mod4Mask,              XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
	{ Super|Mod4Mask,              XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
	{ Super|Mod4Mask|ShiftMask,    XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
	{ Super|Mod4Mask|ShiftMask,    XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
	{ Super|Mod4Mask|ShiftMask,    XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
	{ Super|Mod4Mask|ShiftMask,    XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
	{ Altkey,                      XK_u,          incrgaps,               {.i = +1 } },
	{ Altkey|ShiftMask,            XK_u,          incrgaps,               {.i = -1 } },
	{ Super|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ Super|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ Super|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ Super|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ Super|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ Super|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ Super|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ Super|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ Super|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ Super|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ Super|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ Super|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ Super|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ Super|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },

	//{ Super,                       XK_space,      setlayout,              {0} },
	{ Super|ControlMask|ShiftMask, XK_h,          togglehorizontalmax,    {0} },
	{ Super|ControlMask|ShiftMask, XK_l,          togglehorizontalmax,    {0} },
	{ Super|ControlMask|ShiftMask, XK_j,          toggleverticalmax,      {0} },
	{ Super|ControlMask|ShiftMask, XK_k,          toggleverticalmax,      {0} },
	{ Super|ControlMask,           XK_m,          togglemax,              {0} },
	{ Super|ShiftMask,             XK_Escape,     togglenomodbuttons,     {0} },
	{ Super,                       XK_0,          view,                   {.ui = ~0 } },
	{ Super|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ Super,                       XK_comma,      focusmon,               {.i = -1 } },
	{ Super,                       XK_period,     focusmon,               {.i = +1 } },
	{ Super|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ Super|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	{ Super|ControlMask,           XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_VIEW } },
	{ Super|ControlMask,           XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_VIEW } },
	{ Super|ControlMask,           XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_VIEW } },
	{ Super|ControlMask,           XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_VIEW } },
	{ Super|Mod4Mask,              XK_Up,         switchtag,              { .ui = SWITCHTAG_UP    | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ Super|Mod4Mask,              XK_Down,       switchtag,              { .ui = SWITCHTAG_DOWN  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ Super|Mod4Mask,              XK_Right,      switchtag,              { .ui = SWITCHTAG_RIGHT | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	{ Super|Mod4Mask,              XK_Left,       switchtag,              { .ui = SWITCHTAG_LEFT  | SWITCHTAG_TAG | SWITCHTAG_VIEW } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         Super,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         Super,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         Super,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            Super,              Button1,        tag,            {0} },
	{ ClkTagBar,            Super,              Button3,        toggletag,      {0} },
};


