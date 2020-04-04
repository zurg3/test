#include <QString>
#include <QSysInfo>

constexpr auto app_version = "0.2.10";

constexpr auto app_version_major = 0;
constexpr auto app_version_minor = 2;
constexpr auto app_version_patch = 10;

constexpr auto app_build = "34";

const QString app_full_version = app_version + QString(" (") + app_build + QString(")") + QString(" ") + QSysInfo::buildCpuArchitecture();
