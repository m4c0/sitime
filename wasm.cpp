module sitime;
import vaselin;

uint64_t sitime::current_timestamp() {
  return vaselin::date_now();
}
