//
// Created by alexander on 25.02.18.
//

#include "CEmailTools.h"

namespace server {

    // TODO: Configure sendmail
    bool CEmailTools::send(std::string from, std::string to, std::string subject, std::string message) {
        FILE *mailpipe = popen("/usr/lib/sendmail -t", "w");
        if (mailpipe == nullptr)
            return false;

        fprintf(mailpipe, "To: %s\n", to.c_str());
        fprintf(mailpipe, "From: %s\n", from.c_str());
        fprintf(mailpipe, "Subject: %s\n\n", subject.c_str());
        fwrite(message.c_str(), 1, message.size(), mailpipe);
        fwrite(".\n", 1, 2, mailpipe);

        pclose(mailpipe);
        return true;
    }

}