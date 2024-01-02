//#include <X11/XF86keysym.h>
#define XK_3270_PrintScreen              0xfd1d
#define XF86XK_AudioLowerVolume 0x1008FF11
#define XF86XK_AudioMute        0x1008FF12
#define XF86XK_AudioRaiseVolume 0x1008FF13
/* key definitions */
#define Super Mod4Mask
#define Altkey Mod1Mask
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
static const char *termcmd[]  = { "alacritty", NULL };
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
  /* print screen */
  { 0,    XK_3270_PrintScreen,              spawn, SHCMD("scrot")},     // 截屏
  { 0,    XF86XK_AudioRaiseVolume,          spawn,          SHCMD("volume up") },
  { 0,    XF86XK_AudioLowerVolume,          spawn,          SHCMD("volume down") },
  { 0,    XF86XK_AudioMute,                 spawn,          SHCMD("volume toggle") },
  /* client */
	{ Altkey|ShiftMask,               XK_q,       killclient,       {0} },
	{ Altkey|ShiftMask,               XK_Return,  zoom,             {0} },
  { Altkey,                         XK_j,       focusstack,       {.i = +1} },
  { Altkey,                         XK_k,       focusstack,       {.i = -1} },
  //{ Altkey|ShiftMask,               XK_j,       movestack,        {.i = +1} },
  //{ Altkey|ShiftMask,               XK_k,       movestack,        {.i = -1} },
	{ Altkey|ShiftMask,               XK_h,       setmfact,         {.f = -0.05} },
	{ Altkey|ShiftMask,               XK_l,       setmfact,         {.f = +0.05} },
  { Altkey|ShiftMask,               XK_space,   togglefloating,   {0} },
  //{ Altkey,                         XK_f,       togglefullscreen, {0} },
	{ Super,                          XK_Tab,     view,             {0} },

  /* layout */
	{ Super,                      XK_t,       setlayout,      {.v = &layouts[0]} },
	{ Super,                      XK_f,       setlayout,      {.v = &layouts[1]} },
	{ Super,                      XK_m,       setlayout,      {.v = &layouts[2]} },
	//{ Super,                      XK_p,       cyclelayout,            {.i = -1 } },
	//{ Super,                      XK_n,       cyclelayout,            {.i = +1 } },

	{ Super,                       XK_i,          incnmaster,             {.i = +1 } },
	{ Super,                       XK_d,          incnmaster,             {.i = -1 } },
	{ Super,                       XK_0,          view,                   {.ui = ~0 } },
	{ Super|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ Super,                       XK_comma,      focusmon,               {.i = -1 } },
	{ Super,                       XK_period,     focusmon,               {.i = +1 } },
	{ Super|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ Super|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
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
