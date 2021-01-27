#include <iostream>
#include <mpd/client.h>

std::string music() {
    struct mpd_connection *conn;

    conn = mpd_connection_new("localhost", 6600, 1000);

    if (mpd_connection_get_error(conn) != MPD_ERROR_SUCCESS) {
    mpd_connection_free(conn);
    return "N/A (could not connect to MPD)";
    }
    struct mpd_song *song;
    song = mpd_run_current_song(conn);
	const char *title_char = mpd_song_get_tag(song, MPD_TAG_TITLE, 0);
	const char *album_char = mpd_song_get_tag(song, MPD_TAG_ALBUM, 0);
	const char *artist_char = mpd_song_get_tag(song, MPD_TAG_ARTIST, 0);
    std::string title = title_char;
    std::string album = album_char;
    std::string artist = artist_char;
    std::string message = artist
        + std::string(" - ")
        + album
        + std::string(" - ")
        + title;
    return message;
}
