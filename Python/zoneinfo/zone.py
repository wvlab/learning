# TODO more usage
from datetime import datetime
from zoneinfo import ZoneInfo

# Раньше вместо модуля стандартной библиотеки Python использовали
# модуль pytz, однако уже Django 4.x использует zoneinfo

# zoneinfo взаимодействует со стандартной библиотекой datetime
dt = datetime.now()
# Иницилизируем классы часовых поясов
UTC_tz = ZoneInfo("UTC")
KIEV_tz = ZoneInfo("Europe/Kiev")
MOSCOW_tz = ZoneInfo("Europe/Moscow")
# Переведём часовые пояса
dt_utc = dt.astimezone(UTC_tz)
dt_kiev = dt.astimezone(KIEV_tz)
dt_msk = dt.astimezone(MOSCOW_tz)

print(f"Время по UTC: {dt_utc}")
print(f"Время по Киеву: {dt_kiev}")
print(f"Время по Москве: {dt_msk}")
