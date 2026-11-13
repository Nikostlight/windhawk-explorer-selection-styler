// ==WindhawkMod==
// @id              explorer-selection-border
// @name            Explorer Selection Border
// @description     Recolors the selection, hover highlight, navigation pane, column headers and tooltips of File Explorer
// @version         1.2
// @author          Spoky
// @include         explorer.exe
// @architecture    x86-64
// @compilerOptions -lgdiplus -luxtheme -lgdi32 -lmsimg32
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Explorer Selection Styler

File Explorer draws the keyboard focus with a thin, opaque grey rectangle and
the hover/selection highlights with flat grey fills. None of that can be
recolored through Windows settings.

This mod replaces those theme parts with its own painting: a translucent fill
and a rounded border of any color for the selected item, a softer fill for the
hovered one, plus matching colors for the navigation pane, the column headers
and the tooltips. Everything is drawn with rounded corners and scales with the
monitor DPI.

## What it changes

- **File list** - selection fill + border, hover fill, no stock grey left behind
- **Navigation pane** - hover and selection of the tree items
- **Column headers** ("Name", "Date modified", ...) - hover and pressed states
- **Tooltips** - background, border and rounded window corners
- **Details pane header** and the other themed item rows are left untouched

## Screenshots

![Selection and hover](https://raw.githubusercontent.com/Nikostlight/windhawk-explorer-selection-styler/main/screenshots/01-selection.png)

The file list: one selected item with a border, another one hovered.

![Navigation pane](https://raw.githubusercontent.com/Nikostlight/windhawk-explorer-selection-styler/main/screenshots/02-navigation.png)

The navigation pane uses the same palette as the file list.

![Column headers](https://raw.githubusercontent.com/Nikostlight/windhawk-explorer-selection-styler/main/screenshots/03-columns.png)

Hovering a column header paints it with the hover fill instead of the stock
grey rectangle.

![Tooltip](https://raw.githubusercontent.com/Nikostlight/windhawk-explorer-selection-styler/main/screenshots/04-tooltip.png)

Tooltips are recolored and get rounded corners.

## Settings

**Windhawk 2.0** draws a real settings form: a color picker with a swatch for
every color and a slider for every opacity, thickness and radius.
**Windhawk 1.7.3** shows plain text and number fields, the mod works the same
there, only without the pickers and sliders.

Pick one of nine color themes. The first eight are ready palettes, numbered and
shown with a color square (`1` blue, `2` violet, `3` teal, `4` green, `5` orange,
`6` crimson, `7` magenta, `8` graphite); the ninth, *Custom colors*, reveals the
color pickers below. A theme recolors the border, the fill and the tooltips at
once; opacity and geometry stay as you set them.

The first group controls the selection: border color, border opacity,
thickness, corner radius and inset, then the fill color and the fill opacity
for the selected and the hovered item.

The second group controls the tooltips: whether they are restyled at all, the
background color, the border color and the corner radius. Set the restyling
toggle to `off` if you prefer the stock tooltips.

Colors are hex RGB values, for example `#0078D4`. Opacity is `0` (invisible) to
`100` (solid). Thickness, radius and inset are in pixels at 100% DPI and are
scaled automatically on monitors with a different scale factor.

## Notes

- Works in File Explorer only (`explorer.exe`). Open/Save dialogs hosted by
  other applications are not affected.
- The mod relies on undocumented theme details (`ItemsView`, `ListView`,
  `TreeView`, `Header` and `Tooltip` parts). A future Windows update could
  change them, in which case the mod simply stops having an effect.
- Toggling the mod or changing a setting takes effect immediately, without
  restarting Explorer.
- The stock drawing is replaced, not hidden: if the mod fails to draw, nothing
  is drawn for that part.

## Русский

Мод перекрашивает выделение и наведение в Проводнике Windows 11: заливка и
скруглённая рамка выбранного элемента, отдельная заливка для элемента под
курсором, та же палитра для панели навигации и заголовков колонок («Имя»,
«Дата», «Тип», «Размер»), а также фон, рамка и скругление всплывающих подсказок.

Настройки: цвет и прозрачность рамки, цвет и прозрачность заливки, отдельная
прозрачность для наведения, толщина рамки, радиус скругления и отступ. Для
подсказок есть отдельный переключатель, цвет фона, цвет рамки и радиус.

В Windhawk 2.0 настройки рисуются настоящей формой: у каждого цвета есть
квадратик-образец и окно выбора цвета, у каждой прозрачности, толщины и
радиуса — ползунок с полем числа. Готовых тем девять: `1` синяя, `2`
фиолетовая, `3` бирюзовая, `4` зелёная, `5` оранжевая, `6` малиновая, `7`
пурпурная, `8` графитовая, `9` — свои цвета (тогда появляются пикеры). Тема
меняет цвет рамки, заливки и подсказок, а прозрачность и геометрия остаются
вашими. В Windhawk 1.7.3 те же настройки показаны обычными полями.
*/
// ==/WindhawkModReadme==

// ==WindhawkModSettings==
/*
# Color theme
- preset: custom
  $name: Color theme
  $description: "1-8 are ready palettes, the square shows the color and the number is its index. 9 keeps your own colors, the pickers below then appear."
  $options:
    - windowsBlue: "1  🟦  Windows blue (#0078D4)"
    - violet: "2  🟪  Violet (#8B5CF6)"
    - teal: "3  🟩  Teal (#2AA198)"
    - green: "4  🟢  Green (#37A64B)"
    - orange: "5  🟧  Orange (#E8862E)"
    - crimson: "6  🟥  Crimson (#E0455A)"
    - magenta: "7  💜  Magenta (#C445B8)"
    - graphite: "8  ⬛  Graphite (#6E7B8B)"
    - custom: "9  🎨  Custom colors (pickers below)"
# Selection
- color: "#0078D4"
  $name: Border color
  $description: "Hex RGB color of the selection border, for example #0078D4"
  #! $format: colorRgb
  #! $showIf: {preset: custom}
- opacity: 100
  $name: Border opacity
  $description: 0 (invisible) to 100 (solid)
  #! $min: 0
  #! $max: 100
  #! $format: slider
- thickness: 1
  $name: Border thickness
  $description: Border width in pixels, 1 to 6
  #! $min: 1
  #! $max: 6
  #! $format: slider
- radius: 4
  $name: Corner radius
  $description: Pixels, 0 for sharp corners
  #! $min: 0
  #! $max: 24
  #! $format: slider
- inset: 1
  $name: Border inset
  $description: Distance in pixels between the item edge and the border
  #! $min: 0
  #! $max: 12
  #! $format: slider
# Fill
- fillColor: "#0078D4"
  $name: Fill color
  $description: "Hex RGB color of the selection and hover fill, for example #0078D4"
  #! $format: colorRgb
  #! $showIf: {preset: custom}
- fillOpacity: 35
  $name: Selection fill opacity
  $description: 0 (transparent) to 100 (solid)
  #! $min: 0
  #! $max: 100
  #! $format: slider
- hoverFillOpacity: 18
  $name: Hover fill opacity
  $description: Fill opacity for the item under the mouse pointer
  #! $min: 0
  #! $max: 100
  #! $format: slider
# Tooltips
- tooltipEnabled: true
  $name: Restyle tooltips
  $description: Repaint Explorer tooltips and round their corners, or keep the stock ones
- tooltipColor: "#103051"
  $name: Tooltip background color
  $description: "Hex RGB color of the tooltip background, for example #103051"
  #! $format: colorRgb
  #! $showIf: {tooltipEnabled: true, preset: custom}
- tooltipBorderColor: "#0078D4"
  $name: Tooltip border color
  $description: "Hex RGB color of the 1px tooltip border, for example #0078D4"
  #! $format: colorRgb
  #! $showIf: {tooltipEnabled: true, preset: custom}
- tooltipRadius: 6
  $name: Tooltip corner radius
  $description: Pixels, 0 for sharp corners
  #! $min: 0
  #! $max: 24
  #! $format: slider
  #! $showIf: {tooltipEnabled: true}
*/
// ==/WindhawkModSettings==

#include <windows.h>
#include <uxtheme.h>

#ifndef WH_MOD_ID
#define WH_MOD_ID L"explorer-selection-border"
#endif
#ifndef WH_MOD_VERSION
#define WH_MOD_VERSION L"1.0"
#endif

#include <windhawk_api.h>
#include <windhawk_utils.h>

#include <gdiplus.h>

#include <algorithm>
#include <cstdarg>
#include <cstdio>
#include <cwchar>
#include <cwctype>
#include <string>

namespace {

#ifdef SELECTION_BORDER_DIAG
void DiagLog(const wchar_t* format, ...) {
    wchar_t buffer[1024];
    va_list args;
    va_start(args, format);
    _vsnwprintf_s(buffer, _TRUNCATE, format, args);
    va_end(args);

    HANDLE file = CreateFileW(L"C:\\Temp\\opencode\\windhawk\\modlog.txt",
                              FILE_APPEND_DATA, FILE_SHARE_READ | FILE_SHARE_WRITE,
                              nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (file == INVALID_HANDLE_VALUE) {
        return;
    }

    char utf8[4096];
    int size = WideCharToMultiByte(CP_UTF8, 0, buffer, -1, utf8, sizeof(utf8),
                                   nullptr, nullptr);
    DWORD written = 0;
    if (size > 1) {
        WriteFile(file, utf8, static_cast<DWORD>(size - 1), &written, nullptr);
    }
    WriteFile(file, "\r\n", 2, &written, nullptr);
    CloseHandle(file);
}
#endif

struct Settings {
    Gdiplus::Color color{255, 0, 120, 212};
    Gdiplus::Color fillColor{255, 0, 120, 212};
    Gdiplus::Color tooltipColor{255, 16, 48, 81};
    Gdiplus::Color tooltipBorderColor{255, 0, 120, 212};
    int opacity = 100;
    int fillOpacity = 35;
    int hoverFillOpacity = 18;
    int thickness = 1;
    int radius = 4;
    int inset = 1;
    bool tooltipEnabled = true;
    int tooltipRadius = 6;
};

Settings g_settings;
ULONG_PTR g_gdiplusToken = 0;

bool ParseHexColor(const wchar_t* text, Gdiplus::Color* color) {
    if (!text) {
        return false;
    }

    std::wstring value(text);
    while (!value.empty() && iswspace(value.front())) {
        value.erase(value.begin());
    }
    while (!value.empty() && iswspace(value.back())) {
        value.pop_back();
    }

    if (!value.empty() && value.front() == L'#') {
        value.erase(value.begin());
    }

    if (value.size() != 6) {
        return false;
    }

    wchar_t* end = nullptr;
    unsigned long rgb = wcstoul(value.c_str(), &end, 16);
    if (!end || *end != L'\0') {
        return false;
    }

    *color = Gdiplus::Color(255, static_cast<BYTE>((rgb >> 16) & 0xFF),
                            static_cast<BYTE>((rgb >> 8) & 0xFF),
                            static_cast<BYTE>(rgb & 0xFF));
    return true;
}

int ReadIntSetting(const wchar_t* name, int defaultValue, int minValue,
                   int maxValue) {
    int value = defaultValue;

    const wchar_t* text = Wh_GetStringSetting(name);
    if (text && *text) {
        value = _wtoi(text);
    }
    if (text) {
        Wh_FreeStringSetting(text);
    }

    return std::clamp(value, minValue, maxValue);
}

Gdiplus::Color ParseColorSetting(const wchar_t* name,
                                 const Gdiplus::Color& fallback) {
    Gdiplus::Color color = fallback;

    const wchar_t* text = Wh_GetStringSetting(name);
    if (text && *text) {
        ParseHexColor(text, &color);
    }
    if (text) {
        Wh_FreeStringSetting(text);
    }

    return color;
}

// A ready-made palette. Only the accent color and the tooltip background are
// stored per theme; the fill and the tooltip border reuse the accent.
struct ColorPreset {
    const wchar_t* id;
    COLORREF accent;
    COLORREF tooltip;
};

const ColorPreset kColorPresets[] = {
    {L"windowsBlue", RGB(0x00, 0x78, 0xD4), RGB(0x10, 0x30, 0x51)},
    {L"violet", RGB(0x8B, 0x5C, 0xF6), RGB(0x24, 0x1A, 0x3D)},
    {L"teal", RGB(0x2A, 0xA1, 0x98), RGB(0x0E, 0x2F, 0x2C)},
    {L"green", RGB(0x37, 0xA6, 0x4B), RGB(0x10, 0x33, 0x1A)},
    {L"orange", RGB(0xE8, 0x86, 0x2E), RGB(0x3A, 0x24, 0x10)},
    {L"crimson", RGB(0xE0, 0x45, 0x5A), RGB(0x3A, 0x12, 0x19)},
    {L"magenta", RGB(0xC4, 0x45, 0xB8), RGB(0x3A, 0x14, 0x36)},
    {L"graphite", RGB(0x6E, 0x7B, 0x8B), RGB(0x22, 0x29, 0x32)},
};

Gdiplus::Color RgbColor(COLORREF rgb) {
    return Gdiplus::Color(255, GetRValue(rgb), GetGValue(rgb), GetBValue(rgb));
}

std::wstring ReadStringSetting(const wchar_t* name) {
    std::wstring value;

    const wchar_t* text = Wh_GetStringSetting(name);
    if (text) {
        value = text;
        Wh_FreeStringSetting(text);
    }

    return value;
}

const ColorPreset* FindColorPreset(const std::wstring& id) {
    for (const ColorPreset& preset : kColorPresets) {
        if (id == preset.id) {
            return &preset;
        }
    }

    return nullptr;
}

void LoadSettings() {
    // A theme overrides the color pickers, which the settings editor hides
    // while one is selected. "custom" (or an unknown value) uses the pickers.
    const ColorPreset* preset = FindColorPreset(ReadStringSetting(L"preset"));

    if (preset) {
        g_settings.color = RgbColor(preset->accent);
        g_settings.fillColor = g_settings.color;
        g_settings.tooltipColor = RgbColor(preset->tooltip);
        g_settings.tooltipBorderColor = g_settings.color;
    } else {
        g_settings.color = ParseColorSetting(L"color", g_settings.color);
        g_settings.fillColor =
            ParseColorSetting(L"fillColor", g_settings.fillColor);
        g_settings.tooltipColor =
            ParseColorSetting(L"tooltipColor", g_settings.tooltipColor);
        g_settings.tooltipBorderColor = ParseColorSetting(
            L"tooltipBorderColor", g_settings.tooltipBorderColor);
    }

    g_settings.opacity = ReadIntSetting(L"opacity", 100, 0, 100);
    g_settings.fillOpacity = ReadIntSetting(L"fillOpacity", 35, 0, 100);
    g_settings.hoverFillOpacity =
        ReadIntSetting(L"hoverFillOpacity", 18, 0, 100);
    g_settings.thickness = ReadIntSetting(L"thickness", 1, 1, 6);
    g_settings.radius = ReadIntSetting(L"radius", 4, 0, 24);
    g_settings.inset = ReadIntSetting(L"inset", 1, 0, 12);
    g_settings.tooltipEnabled = ReadIntSetting(L"tooltipEnabled", 1, 0, 1) != 0;
    g_settings.tooltipRadius = ReadIntSetting(L"tooltipRadius", 6, 0, 24);
}

void AddRoundedRect(Gdiplus::GraphicsPath* path,
                    const Gdiplus::RectF& rect,
                    Gdiplus::REAL radius) {
    if (radius <= 0.0f) {
        path->AddRectangle(rect);
        return;
    }

    Gdiplus::REAL diameter = radius * 2;
    Gdiplus::REAL right = rect.X + rect.Width;
    Gdiplus::REAL bottom = rect.Y + rect.Height;

    path->AddArc(rect.X, rect.Y, diameter, diameter, 180.0f, 90.0f);
    path->AddArc(right - diameter, rect.Y, diameter, diameter, 270.0f, 90.0f);
    path->AddArc(right - diameter, bottom - diameter, diameter, diameter, 0.0f,
                 90.0f);
    path->AddArc(rect.X, bottom - diameter, diameter, diameter, 90.0f, 90.0f);
    path->CloseFigure();
}

bool GetThemeClassName(HTHEME theme, wchar_t* buffer, int bufferCount) {
    using GetThemeClass_t = HRESULT(WINAPI*)(HTHEME, LPWSTR, int);

    static auto getThemeClass = reinterpret_cast<GetThemeClass_t>(
        GetProcAddress(GetModuleHandleW(L"uxtheme.dll"), MAKEINTRESOURCEA(74)));

    if (!getThemeClass || !theme || !buffer) {
        return false;
    }

    return SUCCEEDED(getThemeClass(theme, buffer, bufferCount));
}

bool IsItemsViewTheme(HTHEME theme) {
    wchar_t className[256] = {};
    if (!GetThemeClassName(theme, className, ARRAYSIZE(className))) {
        return false;
    }

    return _wcsicmp(className, L"ItemsView") == 0;
}

// Part 3, state 1 is the focus border of the item view on current Windows
// builds. State 2 is handled separately by IsItemsViewHotRow.
bool IsFocusBorder(HTHEME theme, int partId, int stateId) {
    return partId == 3 && stateId == 1 && IsItemsViewTheme(theme);
}

// The item view sometimes paints the hover row itself instead of letting the
// ListView theme do it: part 3, state 2 is the hot state of the same row
// rectangle. On current builds that path leaves the stock grey behind once the
// selection was cleared, so it is painted with our hover fill as well.
bool IsItemsViewHotRow(HTHEME theme, int partId, int stateId) {
    return partId == 3 && stateId == 2 && IsItemsViewTheme(theme);
}

// The file list of current Windows builds paints each row with the classic
// ListView theme (part 1 = list item) even though it is a DirectUI control:
// state 2 = hot, 3 = selected, 5 = hot selected, 6 = selected without focus.
// The navigation pane is a plain tree view and uses part 1 of the TreeView
// theme with the same state numbering for its rows.
bool IsItemRow(HTHEME theme, int partId, int stateId) {
    if (partId != 1) {
        return false;
    }
    if (stateId != 2 && stateId != 3 && stateId != 5 && stateId != 6) {
        return false;
    }

    wchar_t className[256] = {};
    if (!GetThemeClassName(theme, className, ARRAYSIZE(className))) {
        return false;
    }

    return _wcsicmp(className, L"ListView") == 0 ||
           _wcsicmp(className, L"ItemsView") == 0 ||
           _wcsicmp(className, L"TreeView") == 0 ||
           _wcsicmp(className, L"TreeViewStyle") == 0;
}

// The column header of the file list ("Name", "Date modified", ...) is a
// themed Header control drawn by DirectUI in a memory DC. Part 1 is a column
// item; states 2 and up are hot/pressed/sorted variants that paint the stock
// grey rectangle: 2 = hot, 3 = pressed, 4/5 = sorted, 7/8 = sorted with the
// sort icon. They are painted with the same fill as the list rows instead.
bool IsHeaderItem(HTHEME theme, int partId, int stateId) {
    if (partId != 1 || stateId < 2 || stateId > 8) {
        return false;
    }

    wchar_t className[256] = {};
    if (!GetThemeClassName(theme, className, ARRAYSIZE(className))) {
        return false;
    }

    return _wcsicmp(className, L"Header") == 0;
}

void DrawBorder(HDC hdc, const RECT* rect, const RECT* clipRect) {
    if (!rect || g_settings.opacity <= 0) {
        return;
    }

    Gdiplus::Graphics graphics(hdc);
    if (graphics.GetLastStatus() != Gdiplus::Ok) {
        return;
    }

    graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
    graphics.SetPixelOffsetMode(Gdiplus::PixelOffsetModeHalf);
    graphics.SetCompositingMode(Gdiplus::CompositingModeSourceOver);

    if (clipRect) {
        graphics.SetClip(Gdiplus::Rect(clipRect->left, clipRect->top,
                                       clipRect->right - clipRect->left,
                                       clipRect->bottom - clipRect->top));
    }

    Gdiplus::REAL thickness = static_cast<Gdiplus::REAL>(g_settings.thickness);
    // The stroke straddles the path, so move the path inwards by half of the
    // pen width to keep the whole border inside the item.
    Gdiplus::REAL inset =
        static_cast<Gdiplus::REAL>(g_settings.inset) + thickness / 2.0f;

    Gdiplus::RectF frame(static_cast<Gdiplus::REAL>(rect->left) + inset,
                         static_cast<Gdiplus::REAL>(rect->top) + inset,
                         static_cast<Gdiplus::REAL>(rect->right - rect->left) -
                             inset * 2,
                         static_cast<Gdiplus::REAL>(rect->bottom - rect->top) -
                             inset * 2);

    if (frame.Width <= 0.0f || frame.Height <= 0.0f) {
        return;
    }

    Gdiplus::REAL radius =
        std::min(static_cast<Gdiplus::REAL>(g_settings.radius),
                 std::min(frame.Width, frame.Height) / 2.0f);

    Gdiplus::GraphicsPath path;
    AddRoundedRect(&path, frame, radius);

    BYTE alpha = static_cast<BYTE>(g_settings.opacity * 255 / 100);
    Gdiplus::Pen pen(Gdiplus::Color(alpha, g_settings.color.GetR(),
                                    g_settings.color.GetG(),
                                    g_settings.color.GetB()),
                     thickness);
    pen.SetLineJoin(Gdiplus::LineJoinRound);
    graphics.DrawPath(&pen, &path);
}

// Paints the whole item row: a translucent fill and, for a selected row, a
// border, replacing the stock theme drawing for that state.
void DrawItemRow(HDC hdc, const RECT* rect, bool selected) {
    if (!rect) {
        return;
    }

    Gdiplus::Graphics graphics(hdc);
    if (graphics.GetLastStatus() != Gdiplus::Ok) {
        return;
    }

    graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
    graphics.SetPixelOffsetMode(Gdiplus::PixelOffsetModeHalf);
    graphics.SetCompositingMode(Gdiplus::CompositingModeSourceOver);

    // The clip rectangle a theme function receives is the invalidation area of
    // this paint pass, not the row's own bounds. Clipping the fill to it would
    // leave the row only partially painted, so it is ignored; the device
    // context already clips to the window.

    // Windows sizes the selection highlight in DIPs, so the pixel values are
    // scaled by the monitor DPI the window is drawn on.
    int dpi = GetDeviceCaps(hdc, LOGPIXELSX);
    Gdiplus::REAL scale =
        static_cast<Gdiplus::REAL>(dpi > 0 ? dpi : 96) / 96.0f;

    Gdiplus::REAL thickness =
        static_cast<Gdiplus::REAL>(g_settings.thickness) * scale;
    Gdiplus::REAL inset =
        (static_cast<Gdiplus::REAL>(g_settings.inset) + thickness / 2.0f);

    Gdiplus::RectF frame(static_cast<Gdiplus::REAL>(rect->left) + inset,
                         static_cast<Gdiplus::REAL>(rect->top) + inset,
                         static_cast<Gdiplus::REAL>(rect->right - rect->left) -
                             inset * 2,
                         static_cast<Gdiplus::REAL>(rect->bottom - rect->top) -
                             inset * 2);

    if (frame.Width <= 0.0f || frame.Height <= 0.0f) {
        return;
    }

    Gdiplus::REAL radius =
        std::min(static_cast<Gdiplus::REAL>(g_settings.radius) * scale,
                 std::min(frame.Width, frame.Height) / 2.0f);

    Gdiplus::GraphicsPath path;
    AddRoundedRect(&path, frame, radius);

    int fillOpacity =
        selected ? g_settings.fillOpacity : g_settings.hoverFillOpacity;

    if (fillOpacity > 0) {
        BYTE fillAlpha = static_cast<BYTE>(fillOpacity * 255 / 100);
        Gdiplus::SolidBrush fill(Gdiplus::Color(
            fillAlpha, g_settings.fillColor.GetR(), g_settings.fillColor.GetG(),
            g_settings.fillColor.GetB()));
        graphics.FillPath(&fill, &path);
    }

    if (selected && g_settings.opacity > 0) {
        BYTE alpha = static_cast<BYTE>(g_settings.opacity * 255 / 100);
        Gdiplus::Pen pen(Gdiplus::Color(alpha, g_settings.color.GetR(),
                                        g_settings.color.GetG(),
                                        g_settings.color.GetB()),
                         thickness);
        pen.SetLineJoin(Gdiplus::LineJoinRound);
        graphics.DrawPath(&pen, &path);
    }
}

bool IsTooltipTheme(HTHEME theme) {
    wchar_t className[256] = {};
    if (!GetThemeClassName(theme, className, ARRAYSIZE(className))) {
        return false;
    }

    return _wcsicmp(className, L"Tooltip") == 0 ||
           _wcsicmp(className, L"TooltipStyle") == 0;
}

// Part 1, state 0 is the plain tooltip window background (the grey fill and
// the 1px grey border around the text).
bool IsTooltipBackground(HTHEME theme, int partId, int stateId) {
    return partId == 1 && stateId == 0 && IsTooltipTheme(theme);
}

// The tooltip is a real top-level window, so besides painting a rounded
// background the window itself is given a rounded region. Without the region
// the square corners of the window would still show the stock background.
void RoundTooltipWindow(HDC hdc, int width, int height, int radius) {
    HWND hwnd = WindowFromDC(hdc);
    if (!hwnd) {
        return;
    }

    static HWND cachedHwnd = nullptr;
    static int cachedWidth = 0;
    static int cachedHeight = 0;
    static int cachedRadius = 0;

    if (hwnd == cachedHwnd && width == cachedWidth && height == cachedHeight &&
        radius == cachedRadius) {
        return;
    }

    HRGN region = CreateRoundRectRgn(0, 0, width + 1, height + 1, radius * 2,
                                     radius * 2);
    if (!region) {
        return;
    }

    // On success the window owns the region, it must not be deleted here.
    if (SetWindowRgn(hwnd, region, TRUE)) {
        cachedHwnd = hwnd;
        cachedWidth = width;
        cachedHeight = height;
        cachedRadius = radius;
    } else {
        DeleteObject(region);
    }
}

// Paints the tooltip background with the navigation/selection fill color and
// rounded corners instead of the stock grey rectangle.
void DrawTooltipBackground(HDC hdc, const RECT* rect) {
    if (!rect) {
        return;
    }

    int width = rect->right - rect->left;
    int height = rect->bottom - rect->top;
    if (width <= 0 || height <= 0) {
        return;
    }

    int dpi = GetDeviceCaps(hdc, LOGPIXELSX);
    Gdiplus::REAL scale =
        static_cast<Gdiplus::REAL>(dpi > 0 ? dpi : 96) / 96.0f;

    Gdiplus::REAL radius =
        std::min(static_cast<Gdiplus::REAL>(g_settings.tooltipRadius) * scale,
                 static_cast<Gdiplus::REAL>(std::min(width, height)) / 2.0f);

    RoundTooltipWindow(hdc, width, height,
                       static_cast<int>(radius + 0.5f));

    Gdiplus::Graphics graphics(hdc);
    if (graphics.GetLastStatus() != Gdiplus::Ok) {
        return;
    }

    graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
    graphics.SetPixelOffsetMode(Gdiplus::PixelOffsetModeHalf);
    graphics.SetCompositingMode(Gdiplus::CompositingModeSourceOver);

    Gdiplus::RectF frame(static_cast<Gdiplus::REAL>(rect->left),
                         static_cast<Gdiplus::REAL>(rect->top),
                         static_cast<Gdiplus::REAL>(width),
                         static_cast<Gdiplus::REAL>(height));

    Gdiplus::GraphicsPath path;
    AddRoundedRect(&path, frame, radius);

    // The colors come from the settings, the defaults match the hovered list
    // rows (16/48/81).
    Gdiplus::SolidBrush background(
        Gdiplus::Color(255, g_settings.tooltipColor.GetR(),
                       g_settings.tooltipColor.GetG(),
                       g_settings.tooltipColor.GetB()));
    graphics.FillPath(&background, &path);

    if (g_settings.opacity > 0) {
        BYTE alpha = static_cast<BYTE>(g_settings.opacity * 255 / 100);
        Gdiplus::Pen pen(Gdiplus::Color(alpha, g_settings.tooltipBorderColor.GetR(),
                                        g_settings.tooltipBorderColor.GetG(),
                                        g_settings.tooltipBorderColor.GetB()),
                         1.0f * scale);
        pen.SetLineJoin(Gdiplus::LineJoinRound);
        graphics.DrawPath(&pen, &path);
    }
}

using DrawThemeBackground_t =
    HRESULT(WINAPI*)(HTHEME, HDC, int, int, LPCRECT, LPCRECT);
using DrawThemeBackgroundEx_t = HRESULT(WINAPI*)(HTHEME, HDC, int, int,
                                                 LPCRECT, const DTBGOPTS*);

DrawThemeBackground_t DrawThemeBackground_Original;
DrawThemeBackgroundEx_t DrawThemeBackgroundEx_Original;

HRESULT WINAPI DrawThemeBackground_Hook(HTHEME theme, HDC hdc, int partId,
                                        int stateId, LPCRECT rect,
                                        LPCRECT clipRect) {
#ifdef SELECTION_BORDER_DIAG
    {
        static LONG diagCount = 0;
        if (rect && rect->bottom - rect->top <= 220 &&
            rect->right - rect->left <= 1400 &&
            InterlockedIncrement(&diagCount) <= 200000) {
            wchar_t className[256] = {};
            GetThemeClassName(theme, className, ARRAYSIZE(className));
            DiagLog(L"DTB  part=%d state=%d class=%s rect=%d,%d,%d,%d match=%d row=%d",
                    partId, stateId, className, rect ? rect->left : -1,
                    rect ? rect->top : -1, rect ? rect->right : -1,
                    rect ? rect->bottom : -1,
                    IsFocusBorder(theme, partId, stateId) ? 1 : 0,
                    IsItemRow(theme, partId, stateId) ? 1 : 0);
        }
    }
#endif

    if (g_settings.tooltipEnabled &&
        IsTooltipBackground(theme, partId, stateId)) {
        DrawTooltipBackground(hdc, rect);
        return S_OK;
    }

    if (IsFocusBorder(theme, partId, stateId)) {
        DrawBorder(hdc, rect, clipRect);
        return S_OK;
    }

    if (IsItemRow(theme, partId, stateId) || IsItemsViewHotRow(theme, partId, stateId)) {
        DrawItemRow(hdc, rect, stateId != 2);
        return S_OK;
    }

    if (IsHeaderItem(theme, partId, stateId)) {
        DrawItemRow(hdc, rect, stateId == 3);
        return S_OK;
    }

    return DrawThemeBackground_Original(theme, hdc, partId, stateId, rect,
                                        clipRect);
}

HRESULT WINAPI DrawThemeBackgroundEx_Hook(HTHEME theme, HDC hdc, int partId,
                                          int stateId, LPCRECT rect,
                                          const DTBGOPTS* options) {
#ifdef SELECTION_BORDER_DIAG
    {
        static LONG diagCountEx = 0;
        if (rect && rect->bottom - rect->top <= 220 &&
            rect->right - rect->left <= 1400 &&
            InterlockedIncrement(&diagCountEx) <= 200000) {
            wchar_t className[256] = {};
            GetThemeClassName(theme, className, ARRAYSIZE(className));
            DiagLog(L"DTBEx part=%d state=%d class=%s rect=%d,%d,%d,%d match=%d row=%d",
                    partId, stateId, className, rect ? rect->left : -1,
                    rect ? rect->top : -1, rect ? rect->right : -1,
                    rect ? rect->bottom : -1,
                    IsFocusBorder(theme, partId, stateId) ? 1 : 0,
                    IsItemRow(theme, partId, stateId) ? 1 : 0);
        }
    }
#endif

    if (g_settings.tooltipEnabled &&
        IsTooltipBackground(theme, partId, stateId)) {
        DrawTooltipBackground(hdc, rect);
        return S_OK;
    }

    if (IsFocusBorder(theme, partId, stateId)) {
        DrawBorder(hdc, rect, options ? &options->rcClip : nullptr);
        return S_OK;
    }

    if (IsItemRow(theme, partId, stateId) || IsItemsViewHotRow(theme, partId, stateId)) {
        DrawItemRow(hdc, rect, stateId != 2);
        return S_OK;
    }

    if (IsHeaderItem(theme, partId, stateId)) {
        DrawItemRow(hdc, rect, stateId == 3);
        return S_OK;
    }

    return DrawThemeBackgroundEx_Original(theme, hdc, partId, stateId, rect,
                                          options);
}

using GetThemeColor_t = HRESULT(WINAPI*)(HTHEME, int, int, int, COLORREF*);
GetThemeColor_t GetThemeColor_Original;

HRESULT WINAPI GetThemeColor_Hook(HTHEME theme, int partId, int stateId,
                                  int propId, COLORREF* color) {
    HRESULT result =
        GetThemeColor_Original(theme, partId, stateId, propId, color);

#ifdef SELECTION_BORDER_DIAG
    {
        static LONG diagColors = 0;
        if (InterlockedIncrement(&diagColors) <= 3000) {
            wchar_t className[256] = {};
            GetThemeClassName(theme, className, ARRAYSIZE(className));
            DiagLog(L"COLOR part=%d state=%d prop=%d class=%s value=%06X",
                    partId, stateId, propId, className,
                    color ? (unsigned)*color : 0);
        }
    }
#endif

    return result;
}

using FillRect_t = int(WINAPI*)(HDC, const RECT*, HBRUSH);
using GradientFill_t = BOOL(WINAPI*)(HDC, PTRIVERTEX, ULONG, PVOID, ULONG,
                                     ULONG);

FillRect_t FillRect_Original;
GradientFill_t GradientFill_Original;

int WINAPI FillRect_Hook(HDC hdc, const RECT* rect, HBRUSH brush) {
#ifdef SELECTION_BORDER_DIAG
    if (rect && brush) {
        LOGBRUSH lb = {};
        if (GetObject(brush, sizeof(lb), &lb) == sizeof(lb) &&
            lb.lbStyle == BS_SOLID && rect->bottom - rect->top <= 80 &&
            rect->right - rect->left <= 1400) {
            static LONG diagFills = 0;
            if (InterlockedIncrement(&diagFills) <= 4000) {
                DiagLog(L"FILL %02X%02X%02X rect=%d,%d,%d,%d",
                        GetRValue(lb.lbColor), GetGValue(lb.lbColor),
                        GetBValue(lb.lbColor), rect->left, rect->top,
                        rect->right, rect->bottom);
            }
        }
    }
#endif

    return FillRect_Original(hdc, rect, brush);
}

BOOL WINAPI GradientFill_Hook(HDC hdc, PTRIVERTEX vertices, ULONG vertexCount,
                              PVOID mesh, ULONG meshCount, ULONG mode) {
#ifdef SELECTION_BORDER_DIAG
    if (vertices && vertexCount > 0) {
        static LONG diagGradients = 0;
        if (InterlockedIncrement(&diagGradients) <= 800) {
            DiagLog(L"GRAD %02X%02X%02X..%02X%02X%02X v=%d mode=%d",
                    vertices[0].Red >> 8, vertices[0].Green >> 8,
                    vertices[0].Blue >> 8, vertices[vertexCount - 1].Red >> 8,
                    vertices[vertexCount - 1].Green >> 8,
                    vertices[vertexCount - 1].Blue >> 8, vertexCount, mode);
        }
    }
#endif

    return GradientFill_Original(hdc, vertices, vertexCount, mesh, meshCount,
                                 mode);
}

}  // namespace

BOOL Wh_ModInit() {
    Wh_Log(L"Initializing Explorer Selection Border");

#ifdef SELECTION_BORDER_DIAG
    DiagLog(L"=== Wh_ModInit pid=%lu ===", GetCurrentProcessId());
#endif

    Gdiplus::GdiplusStartupInput startupInput;
    if (Gdiplus::GdiplusStartup(&g_gdiplusToken, &startupInput, nullptr) !=
        Gdiplus::Ok) {
        Wh_Log(L"GdiplusStartup failed");
#ifdef SELECTION_BORDER_DIAG
        DiagLog(L"GdiplusStartup failed");
#endif
        return FALSE;
    }

#ifdef SELECTION_BORDER_DIAG
    DiagLog(L"GdiplusStartup ok");
#endif

    LoadSettings();

#ifdef SELECTION_BORDER_DIAG
    DiagLog(L"settings: color=%02X%02X%02X opacity=%d thickness=%d radius=%d inset=%d",
            g_settings.color.GetR(), g_settings.color.GetG(),
            g_settings.color.GetB(), g_settings.opacity, g_settings.thickness,
            g_settings.radius, g_settings.inset);
#endif

    if (!WindhawkUtils::SetFunctionHook(DrawThemeBackground,
                                        DrawThemeBackground_Hook,
                                        &DrawThemeBackground_Original) ||
        !WindhawkUtils::SetFunctionHook(DrawThemeBackgroundEx,
                                        DrawThemeBackgroundEx_Hook,
                                        &DrawThemeBackgroundEx_Original) ||
        !WindhawkUtils::SetFunctionHook(GetThemeColor, GetThemeColor_Hook,
                                        &GetThemeColor_Original) ||
        !WindhawkUtils::SetFunctionHook(FillRect, FillRect_Hook,
                                        &FillRect_Original) ||
        !WindhawkUtils::SetFunctionHook(GradientFill, GradientFill_Hook,
                                        &GradientFill_Original)) {
        Wh_Log(L"Failed to hook uxtheme");
#ifdef SELECTION_BORDER_DIAG
        DiagLog(L"SetFunctionHook failed");
#endif
        return FALSE;
    }

#ifdef SELECTION_BORDER_DIAG
    DiagLog(L"hooks installed");
#endif

    return TRUE;
}

void Wh_ModSettingsChanged() {
    LoadSettings();
}
